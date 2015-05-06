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
    void align();
    
    void refresh();
    void setOnRefresh(std::function<void()> _set);
    
    void constantSpeed(float speed);
    
    b2Body* getBody();
    Sprite* getSprite();
private:
    b2BodyDef bodyDef;
    b2Body* body;
    Sprite* image = NULL;
    
    std::function<void()> onRefresh = [&](){};
};


#endif /* defined(__GuidedCircle__BPCircleObject__) */
