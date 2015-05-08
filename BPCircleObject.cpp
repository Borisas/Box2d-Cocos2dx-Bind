#include "BPCircleObject.h"


BPCircle* BPCircle::createStatic(float radius, b2World* _to, const char* image){
    auto c = new BPCircle;
    c->setImage(image);
    c->assemble(radius, _to,false);
    return c;
}
BPCircle* BPCircle::createDynamic(float radius, b2World* _to, const char* image){
    auto c = new BPCircle;
    c->setImage(image);
    c->assemble(radius, _to,true);
    return c;
}
BPCircle* BPCircle::createDynamic(float radius, b2World* _to, const char* image, BPMaterial _mat){
    auto c = new BPCircle;
    c->setImage(image);
    c->assemble(radius, _to,true, _mat);
    return c;
}
BPCircle* BPCircle::createStatic(float radius, b2World* _to, const char* image, BPMaterial _mat){
    auto c = new BPCircle;
    c->setImage(image);
    c->assemble(radius, _to,false, _mat);
    return c;
}
void BPCircle::assemble(float radius, b2World* _to, bool dynamic){
    b2CircleShape ballShape;
    ballShape.m_radius = radius / SCALE_RATIO;
    b2FixtureDef ballFixture;
    ballFixture.density=10;
    ballFixture.friction=0.8f;
    ballFixture.restitution=1.f;
    ballFixture.shape=&ballShape;
    b2BodyDef ballBodyDef;
    if(dynamic)
        ballBodyDef.type= b2_dynamicBody;
    
    //ballBodyDef.position.Set(this->getPosition().x/SCALE_RATIO,this->getPosition().y/SCALE_RATIO);
    if(image != NULL)
        ballBodyDef.userData = image;
    
    this->body = _to->CreateBody(&ballBodyDef);
    fx = body->CreateFixture(&ballFixture);
    body->SetGravityScale(10);
}
void BPCircle::assemble(float radius, b2World* _to, bool dynamic, BPMaterial _mat){
    b2CircleShape ballShape;
    ballShape.m_radius = radius / SCALE_RATIO;
    fixture.density=_mat.density;
    fixture.friction=_mat.friction;
    fixture.restitution=_mat.restitution;
    fixture.shape=&ballShape;
    b2BodyDef ballBodyDef;
    if(dynamic)
        ballBodyDef.type= b2_dynamicBody;
    
    //ballBodyDef.position.Set(this->getPosition().x/SCALE_RATIO,this->getPosition().y/SCALE_RATIO);
    if(image != NULL)
        ballBodyDef.userData = image;
    
    this->body = _to->CreateBody(&ballBodyDef);
    fx = body->CreateFixture(&fixture);
    body->SetGravityScale(10);
}
void BPCircle::setImage(const char *image){
    this->image = Sprite::create(image);
    this->addChild(this->image);
}


void BPCircle::setOnRefresh(std::function<void ()> _set){
    this->onRefresh = _set;
}
void BPCircle::BPSetPosition(cocos2d::Vec2 position){
    this->setPosition(Vec2(position.x, position.y));
    this->body->SetTransform(b2Vec2(position.x/SCALE_RATIO, position.y/SCALE_RATIO), this->body->GetAngle());
}
b2Body* BPCircle::BPGetBody(){
    return this->body;
}
Sprite* BPCircle::BPGetSprite(){
    return this->image;
}
b2Fixture* BPCircle::BPGetFixture(){
    return this->fx;
}
void BPCircle::align(){
    this->setPosition(Vec2(body->GetPosition().x * SCALE_RATIO,body->GetPosition().y * SCALE_RATIO));
    this->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
}
void BPCircle::refresh(){
    align();
    constantSpeed(10);
    onRefresh();
}
void BPCircle::constantSpeed(float speed){
    auto rot = body->GetLinearVelocity();
    Vec2 rot2 = Vec2(rot.x, rot.y);
    double angleSin = sin(rot2.getAngle());
    double angleCos = cos(rot2.getAngle());
    if(angleSin < 0.00001 && angleSin > -0.00001)
        angleSin = 0;
    if(angleCos < 0.00001 && angleCos > -0.00001)
        angleCos = 0;
    b2Vec2 setSpeedTo;
    setSpeedTo.x = speed * angleCos;
    setSpeedTo.y = speed * angleSin;
    
    body->SetLinearVelocity(setSpeedTo);
    
}
void BPCircle::setUserData(void *_userData){
    this->fixture.userData = _userData;
}