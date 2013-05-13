//
//  HeroSprite.cpp
//  SamProject02
//
//  Created by  xu on 8/5/13.
//
//

#include "HeroSprite.h"


#define kHero_x_v  5 //x的速度
#define kHero_y_v  5 //x的速度
HeroSprite:: HeroSprite(){



}

HeroSprite::~HeroSprite(){


}

void HeroSprite:: initHeroSpriteWithSpriteFrameName(const char *pszSpriteFrameName){

    this->initWithSpriteFrameName(pszSpriteFrameName);
    m_heroStandAni=CCAnimation::create();
    m_heroStandAni->retain();
    m_heroRunAni=CCAnimation::create();
    m_heroRunAni->retain();
    this->initAnimation(m_heroRunAni, 0.045f, "model_run_%d.png", 16);
    
    this->initAnimation(m_heroStandAni, 0.045f, "model_stand_%d.png", 16);
    
    
}

void HeroSprite::initAnimation(CCAnimation *animation ,float delay,const char* preFormat ,int count){

    char str[100]={0};
    for (int i=1; i<count; i++) {
        sprintf(str, preFormat,i);
        CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        animation->addSpriteFrame(frame);
    }
    animation->setDelayPerUnit(delay);
    

}
void HeroSprite::setHeroStatus(Status pStatus){

    CCAction* action = NULL;
    m_status = pStatus ;
    //        CCLog("===status==%d",m_status);
    switch (m_status) {
        case kStatus_stand:
        {
            
            CCAnimate*   ani = CCAnimate::create(m_heroStandAni);
            action = CCRepeatForever::create(ani);
            action->setTag(kTagAction_stand);
            this->stopActionByTag(kTagAction_run);
        
        }
        break;
        case kStatus_run:
        {
            CCAnimate*   ani = CCAnimate::create(m_heroRunAni);
            action = CCRepeatForever::create(ani);
            action->setTag(kTagAction_run);
            this->stopActionByTag(kTagAction_stand);
        }
            break;
        default:
            break;

    }
    if (action) {
        //this->stopAllActions();
        this->runAction(action);
    }

}


void HeroSprite::move(CCPoint point){

    m_pointTouch=point;
   
    CCPoint nowPoint=this->getPosition();
    m_originalPoint=nowPoint;
    CCPoint subPoint=ccpSub(m_pointTouch, nowPoint);
    
    if(subPoint.x>0){
        this->setFlipX(0);
        hero_x_v=kHero_x_v;
    
    }else{
    
        hero_x_v=-kHero_x_v;
        this->setFlipX(1);
    }
    
    
    

  if (m_status==kStatus_run) {
        return ;
    }

   this->setHeroStatus(kStatus_run);

   this->scheduleUpdate();
    
}


void HeroSprite::update(float fDelta){

    CCPoint oPoint=this->getPosition();
    oPoint.x+=hero_x_v;
    
    if (fabsf(oPoint.x-m_originalPoint.x)>=fabsf(m_pointTouch.x-m_originalPoint.x)) {
        this->stopAllActions();
        this->unscheduleUpdate();
        this->setPosition(oPoint);
        this->setHeroStatus(kStatus_stand);
        
        return;
    }
    this->setPosition(oPoint);
     

}