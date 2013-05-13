//
//  HeroSprite.h
//  SamProject02
//
//  Created by  xu on 8/5/13.
//
//

#ifndef __SamProject02__HeroSprite__
#define __SamProject02__HeroSprite__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
typedef enum{
    kStatus_stand = 0,
    kStatus_run,
    
}Status;
enum{
    kTagAction_stand = 100,
    kTagAction_run,
 
};
class HeroSprite :public cocos2d::CCSprite{
    
private:
    CCPoint m_pointTouch;
     CCPoint m_originalPoint;
    int   hero_x_v;//英雄的速度
    int   hero_y_v;//英雄的速度
public:
    HeroSprite();
    ~HeroSprite();
    Status m_status;
    void initHeroSpriteWithSpriteFrameName(const char *pszSpriteFrameName); //初始化英雄
    
    CCAnimation* m_heroStandAni;  //站立动作
    CCAnimation* m_heroRunAni;    //跑动动作
    
    void initAnimation(CCAnimation *animation ,float delay,const char* preFormat,int count);//初始化动作
    void move(CCPoint point); //移动
    
    void setHeroStatus(Status pStatus); //修改状态
    
    
    virtual void update(float fDelta);
    CREATE_FUNC(HeroSprite);
    
    
};
#endif /* defined(__SamProject02__HeroSprite__) */
