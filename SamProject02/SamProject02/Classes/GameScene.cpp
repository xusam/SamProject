//
//  GameScene.cpp
//  SamProject02
//
//  Created by  xu on 8/5/13.
//
//

#include "GameScene.h"
#include "HeroSprite.h"

GameScene::GameScene(){
    
    
}

GameScene::~GameScene(){
    
    
    
}

CCScene* GameScene::scene(){
    
    
    CCScene * scene=CCScene::create();
    
    GameScene * layer=GameScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
    
}

bool GameScene::init(){
    
    if(!CCLayer::init()){
        
        return false;
    }
    
    
    //添加资源
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hero1.plist", "hero1.png");
    
    //参数初始化
    CCSize size = CCDirector::sharedDirector()-> getWinSize();
    m_touchRect=CCRectMake(48, 40,size.width-2*48, 280);
    
    //注册Touch事件
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    this->initGameScene();
    
    return true;
}


void GameScene::initGameScene(){
    
    //背景
    m_ground=CCSprite::create("62.jpg");
    
    m_ground->setAnchorPoint(ccp(0,0));
    
    m_ground->setPosition(ccp(0, 0));
    
    this->addChild(m_ground);
    
     //英雄
    
    m_HeroSprite=HeroSprite::create();
    m_HeroSprite->initHeroSpriteWithSpriteFrameName("model_stand_1.png");
    m_HeroSprite->cocos2d::CCNode::setPosition(ccp(300, 300));
   
    
    m_ground->addChild(m_HeroSprite);
    
    //m_HeroSprite->setHeroStatus(kStatus_run);
    
}


bool GameScene:: ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent){
    
    CCLog("TouchBegan");
    CCPoint tPoint=pTouch->getLocationInView();
    CCPoint pointGL=  CCDirector::sharedDirector()->convertToGL(tPoint);
    this->heroMoveToPoint(pointGL);
    return true;
    
    
}

void GameScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    CCPoint tPoint=pTouch->getLocationInView();
    CCPoint pointGL=  CCDirector::sharedDirector()->convertToGL(tPoint);
    this->heroMoveToPoint(pointGL);
    
    
}

void GameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    CCLog("TouchEnd");
    CCPoint tPoint=pTouch->getLocationInView();
    CCPoint pointGL=  CCDirector::sharedDirector()->convertToGL(tPoint);
    this->heroMoveToPoint(pointGL);
    
    
}


void GameScene::heroMoveToPoint(CCPoint point){

    if(point.x<m_touchRect.origin.x){
        CCLog("左界面");
        point.x=m_touchRect.origin.x;
    }else{
        if(point.x>(m_touchRect.origin.x+m_touchRect.size.width)){
        CCLog("右界面");
            point.x=m_touchRect.origin.x+m_touchRect.size.width;
        
        }
    
    }
    
    if(point.y<m_touchRect.origin.y){
        CCLog("下界面");
        point.y=m_touchRect.origin.y;
    }else{
        if(point.y>(m_touchRect.origin.y+m_touchRect.size.height)){
            CCLog("上界面");
            point.y=m_touchRect.origin.y+m_touchRect.size.height;
            
        }
        
    }
    m_HeroSprite->move(point);
    

}
