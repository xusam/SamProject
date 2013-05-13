//
//  GameScene.h
//  SamProject02
//
//  Created by  xu on 8/5/13.
//
//

#ifndef __SamProject02__GameScene__
#define __SamProject02__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;

class GameScene:public cocos2d::CCLayer{

private:
    GameScene();
    ~GameScene();
    CCSprite *m_ground;    //背景
    CCRect m_touchRect;  //走动范围
    HeroSprite *m_HeroSprite;//英雄
    

    
public:
   
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void initGameScene();   //初始化背景
    
    void heroMoveToPoint(CCPoint point);  //英雄移动
    
    
    virtual bool ccTouchBegan(CCTouch *pTouch,CCEvent *pEvent);
    
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    

    CREATE_FUNC(GameScene);

};
#endif /* defined(__SamProject02__GameScene__) */
