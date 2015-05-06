#include "BPControler.h"

BPControl* BPControl::create(b2World* to){
    auto c = new BPControl;
    c->init(to);
    return c;
}
void BPControl::init(b2World *to){
    this->localWorldPointer = to;
}
void BPControl::addBP(BPAbstract *_add){
    this->BP.push_back(_add);
}
void BPControl::newDynamicCircle(float radius, const char* image, Layer* addTo, Vec2 pos){
    BPCircle* temp=BPCircle::createDynamic(radius, localWorldPointer, image);
    BP.push_back(temp);
    temp->BPSetPosition(pos);
    addTo->addChild(temp);
    //delete temp;
}
void BPControl::newStaticCircle(float radius, const char* image, Layer* addTo, Vec2 pos){
    BPCircle* temp=BPCircle::createStatic(radius, localWorldPointer, image);
    BP.push_back(temp);
    temp->BPSetPosition(pos);
    addTo->addChild(temp);
    //delete temp;
}
void BPControl::refreshWorld(){
    for(unsigned int i = 0; i < this->BP.size(); i++){
        BP[i]->refresh();
    }
}
void BPControl::BPOSetPosition(Vec2 pos, int element){
    if(element < BP.size() || element == BP_LAST){
        if(element==BP_LAST){
            BP[BP.size()-1]->BPSetPosition(pos);
        }
        else{
            BP[element]->BPSetPosition(pos);
        }
    }
}