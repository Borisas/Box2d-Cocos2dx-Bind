#ifndef BPAbstractBase_h
#define BPAbstractBase_h

#include "cocos2d.h"
USING_NS_CC;

class BPAbstract{
    
public:
    virtual void refresh() = 0;
    virtual void BPSetPosition(Vec2 position) = 0;
    virtual b2Body* BPGetBody() = 0;
    virtual Sprite* BPGetSprite() = 0;
    virtual b2Fixture* BPGetFixture() = 0;
};

#endif /* defined(__GuidedCircle__BPAbstractBase__) */
