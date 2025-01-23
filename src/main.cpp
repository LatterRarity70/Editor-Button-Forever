#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
class $modify(GJButtonsExt, CCMenuItemSpriteExtra) {
	$override void activate() {

		if (this->getID() == "editor-button" and CCScene::get()->getChildByIDRecursive("MenuLayer")) {
			return (void)createQuickPopup(
				"Select Action", 
				"Open <cy>CreatorLayer</c> or call <co>current callback</c>?",
				"CreatorLayer", "Callback", [this](CCNode*, bool btn2) {
					if (!this) return;
					if (btn2) return ((m_pListener ? m_pListener : this)->*m_pfnSelector)(this);
					switchToScene(CreatorLayer::create());
				}
			);
		}

		return CCMenuItemSpriteExtra::activate();
	}
};