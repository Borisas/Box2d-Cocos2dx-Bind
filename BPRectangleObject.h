#ifndef BPRectangleObject_h
#define BPRectangleObject_h

#include "external/Box2D/Box2D.h"
#include "cocos2d.h"
#include <functional>
#include "BPAbstractBase.h"

USING_NS_CC;
using namespace std;

#define SCALE_RATIO 32.0

class BPRectangle : public Node, public BPAbstract{
public:
    static BPRectangle* createStatic(Size box, b2World* _to, const char* image);
    static BPRectangle* createDynamic(Size box, b2World* _to, const char* image);
    
    void setImage(const char* image);
    
    void assemble(Size box, b2World* to, bool dynamic);
    
    void BPSetPosition(Vec2 position);
    void align();
    
    void refresh();
    void setOnRefresh(std::function<void()> _set);
    
    b2Body* getBody();
    Sprite* getSprite();
    b2Fixture* getFixture();
private:
    b2BodyDef bodyDef;

    b2Body* body;
    b2FixtureDef fixture;
    b2Fixture* fx;
    Sprite* image = NULL;
    
    std::function<void()> onRefresh = [&](){};
    
};
#endif /* defined(__GuidedCircle__BPRectangleObject__) */