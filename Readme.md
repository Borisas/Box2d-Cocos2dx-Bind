#Cocos2dx - Box2d binding

Very simple, but it works. Feel free to fork it and change what ever you like )

## How to use:

```c++
#include "BBox2dBind.h"

// ^ for all objects and stuff.

//...
//Create a box2d world:
b2Vec2 gravity = b2Vec2(0.0f, 0.f);
b2World* world = new b2World(gravity);


//Only two types of objects right now
//Circles and Rectangles

BPCircle::createStatic(float radius, b2World* _to, const char* image);
BPRectangle::createStatic(Size box, b2World* _to, const char* image);

//Create a controler:
auto controler=BPControl::create(b2World* to);
controler->addBP(/*BPObjects*/);


//i.e.:
auto circle = BPCircle::createDynamic(16, world, "circle.png");
circle->BPSetPosition(visibleSize.width/2, visibleSize.height/2);
this->addChild(circle);
controler->addBP(circle);
//createStatic - doesn't react to gravity. createDynamic - reacts to gravity

//and activate your controler in your scene update function:
void GameSceneA::update(float dt){
  int positionIterations = 20;
  int velocityIterations = 20;
  world->Step(dt, positionIterations, velocityIterations);
  controler->refreshWorld();
  world->ClearForces();
  world->DrawDebugData();
}


```
