#include "CommInc.h"

#include "GameLogic.h"
#include "GameDisplay.h"
#include "BulletSprite.h"
#include "TankSprite.h"
#include "Skill.h"
#include "BattleGroundScene.h"
#include "Action.h"
#include "MainScene.h"
#include "WHomeScene.h"
#include "GameChapterScene.h"
#include "UnitShowScene.h"
#include "DemoScene.h"
#include "SomeScene.h"
#include "BattleScene.h"
#include "TechTreeScene.h"
#include "GameCtrl.h"


bool CCMainScene::init()
{
    CCScene::init();
    m_pMainSceneLayer = CCMainSceneLayer::create();
    addChild(m_pMainSceneLayer);

    return true;
}

CCMainSceneLayer::CCMainSceneLayer()
{

}

bool CCMainSceneLayer::init()
{
    CCLayerColor::initWithColor(ccc4(204, 232, 207, 64));
    CCSize oSz = CCDirector::sharedDirector()->getVisibleSize();

    m_oMenu.init();
    addChild(&m_oMenu);
    m_oMenu.setPosition(CCPointZero);

    m_oHome.initWithString("Home", this, menu_selector(CCMainSceneLayer::onBtnHomeClick));
    m_oMenu.addChild(&m_oHome);
    m_oHome.setPosition(ccp(oSz.width * 0.85 + m_oHome.getContentSize().width * 0.5, oSz.height * 0.1));

    m_oAttack.initWithString("Attack", this, menu_selector(CCMainSceneLayer::onBtnAttackClick));
    m_oMenu.addChild(&m_oAttack);
    m_oAttack.setPosition(ccp(oSz.width * 0.1 + m_oAttack.getContentSize().width * 0.5, oSz.height * 0.8));

    m_oDefense.initWithString("Defense", this, menu_selector(CCMainSceneLayer::onBtnDefenseClick));
    m_oMenu.addChild(&m_oDefense);
    m_oDefense.setPosition(ccp(oSz.width * 0.1 + m_oDefense.getContentSize().width * 0.5, oSz.height * 0.7));

    m_oResearch.initWithString("Research", this, menu_selector(CCMainSceneLayer::onBtnResearchClick));
    m_oMenu.addChild(&m_oResearch);
    m_oResearch.setPosition(ccp(oSz.width * 0.1 + m_oResearch.getContentSize().width * 0.5, oSz.height * 0.6));

    m_oTroops.initWithString("Troops", this, menu_selector(CCMainSceneLayer::onBtnTroopsClick));
    m_oMenu.addChild(&m_oTroops);
    m_oTroops.setPosition(ccp(oSz.width * 0.1 + m_oTroops.getContentSize().width * 0.5, oSz.height * 0.5));

    m_oAchievement.initWithString("Achievement", this, menu_selector(CCMainSceneLayer::onBtnAchievementClick));
    m_oMenu.addChild(&m_oAchievement);
    m_oAchievement.setPosition(ccp(oSz.width * 0.1 + m_oAchievement.getContentSize().width * 0.5, oSz.height * 0.4));

    m_oDemo.initWithString("Demo", this, menu_selector(CCMainSceneLayer::onBtnDemoClick));
    m_oMenu.addChild(&m_oDemo);
    m_oDemo.setPosition(ccp(oSz.width * 0.1 + m_oDemo.getContentSize().width * 0.5, oSz.height * 0.3));


	m_oBattle.initWithString("Battle", this, menu_selector(CCMainSceneLayer::onBtnBattleClick));
	m_oMenu.addChild(&m_oBattle);
	m_oBattle.setPosition(ccp(oSz.width * 0.1 + m_oBattle.getContentSize().width * 0.5, oSz.height * 0.2));

    return true;
}

void CCMainSceneLayer::onBtnHomeClick( CCObject* pObject )
{
    //CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCHomeScene::create()));
    M_DEF_GM(pGm);
    pGm->popScene();
}

void CCMainSceneLayer::onBtnAttackClick( CCObject* pObject )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCGameChapterScene::create()));
}

void CCMainSceneLayer::onBtnDefenseClick( CCObject* pObject )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCWHomeScene::create()));
}

void CCMainSceneLayer::onBtnResearchClick( CCObject* pObject )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCTechTreeScene::create()));
}

void CCMainSceneLayer::onBtnTroopsClick( CCObject* pObject )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCUnitShowScene::create()));    
}

void CCMainSceneLayer::onBtnAchievementClick( CCObject* pObject )
{

}

void CCMainSceneLayer::onBtnDemoClick( CCObject* pObject )
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCDemoScene::create()));
}

void CCMainSceneLayer::onBtnBattleClick( CCObject* pObject )
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, CCBattleScene::create()));
}