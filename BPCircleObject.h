#ifndef BPCircleObject_h
#define BPCircleObject_h

#include "external/Box2D/Box2D.h"
#include "BPStructures.h"
#include "cocos2d.h"
#include <functional>
#include "BPAbstractBase.h"
#include <iostream>

USING_NS_CC;
using namespace std;

#define SCALE_RATIO 32.0

class BPCircle : public Node, public BPAbstract{
public:
    
    static BPCircle* createStatic(float radius, b2World* _to, const char* image);
    static BPCircle* createDynamic(float radius, b2World* _to, const char* image);
    
    static BPCircle* createStatic(float radius, b2World* _to, const char* image, BPMaterial _mat);
    static BPCircle* createDynamic(float radius, b2World* _to, const char* image, BPMaterial _mat);
    
    
    void setImage(const char* image);
    
    void assemble(float radius, b2World* to, bool dynamic);
    void assemble(float radius, b2World* to, bool dynamic, BPMaterial _mat);
    
    virtual void BPSetPosition(Vec2 position);
    virtual void BPRotate(float angle);
    virtual void BPScale(float scaleX, float scaleY);
    virtual b2Body* BPGetBody();
    virtual Sprite* BPGetSprite();
    virtual b2Fixture* BPGetFixture();
    virtual Node* BPGetNode();
    void align();
    
    void refresh();
    void setOnRefresh(std::function<void()> _set);
    
    void disableAlign();
    void enableAlign();
    
    void disable();
    void enable();
    bool isEnabled();

    void constantSpeed(float speed);
    void setUserData(void * _userData);
    std::function<void()> onRefresh = [&](){};

private:
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2Fixture* fx;
    b2Body* body;
    Sprite* image = NULL;
    
    bool shouldAlign = true;
    bool enabled = true;
};


#endif /* defined(__GuidedCircle__BPCircleObject__) */
