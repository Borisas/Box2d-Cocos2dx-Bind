#ifndef BPControler_h
#define BPControler_h

#include "external/Box2D/Box2D.h"
#include "cocos2d.h"
#include <vector>
#include "BPAbstractBase.h"
#include "BPCircleObject.h"
#include "BPRectangleObject.h"


#define BP_LAST -1

USING_NS_CC;
using namespace std;

class BPControl{
    
public:
    static BPControl* create(b2World* to);
    
    void addBP(BPAbstract* _add);
    void removeBP(int _id, Layer* remove);
    int findBP(BPAbstract* find);
    
    void newDynamicCircle(float radius, const char* image, Layer* addTo, Vec2 pos);
    void newStaticCircle(float radius, const char* image, Layer* addTo, Vec2 pos);
    void init(b2World* to);
    void refreshWorld();
    void BPOSetPosition(Vec2 pos, int element);
private:
    
    b2World* localWorldPointer;
    vector<BPAbstract*> BP;
};

#endif /* defined(__GuidedCircle__BPControler__) */
