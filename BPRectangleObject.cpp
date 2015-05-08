#include "BPRectangleObject.h"


BPRectangle* BPRectangle::createStatic(Size box, b2World* _to, const char* image){
    auto c = new BPRectangle;
    c->setImage(image);
    c->assemble(box, _to,false);
    return c;
}
BPRectangle* BPRectangle::createDynamic(Size box, b2World* _to, const char* image){
    auto c = new BPRectangle;
    c->setImage(image);
    c->assemble(box, _to,true);
    return c;
}
BPRectangle* BPRectangle::createStatic(Size box, b2World* _to, const char* image, BPMaterial _mat){
    auto c = new BPRectangle;
    c->setImage(image);
    c->assemble(box, _to,true);
    return c;
}
BPRectangle* BPRectangle::createDynamic(Size box, b2World* _to, const char* image, BPMaterial _mat){
    auto c = new BPRectangle;
    c->setImage(image);
    c->assemble(box, _to,true);
    return c;
}
void BPRectangle::assemble(Size box, b2World* _to, bool dynamic){
    b2PolygonShape squareShape;
    squareShape.SetAsBox(box.width/ SCALE_RATIO,box.height/ SCALE_RATIO);
    //b2FixtureDef squareFixture;
    fixture.density=10;
    fixture.friction=0.8;
    fixture.restitution=1.f;
    fixture.shape=&squareShape;
    
    b2BodyDef squareBodyDef;
    if(dynamic)
        squareBodyDef.type= b2_dynamicBody;
    
    //ballBodyDef.position.Set(this->getPosition().x/SCALE_RATIO,this->getPosition().y/SCALE_RATIO);
    if(image != NULL)
        squareBodyDef.userData = image;
    
    this->body = _to->CreateBody(&squareBodyDef);
    fx = body->CreateFixture(&fixture);
    body->SetGravityScale(10);
}
void BPRectangle::assemble(Size box, b2World* _to, bool dynamic, BPMaterial _mat){
    b2PolygonShape squareShape;
    squareShape.SetAsBox(box.width/ SCALE_RATIO,box.height/ SCALE_RATIO);
    //b2FixtureDef squareFixture;
    fixture.density=_mat.density;
    fixture.friction=_mat.friction;
    fixture.restitution=_mat.restitution;
    fixture.shape=&squareShape;
    
    b2BodyDef squareBodyDef;
    if(dynamic)
        squareBodyDef.type= b2_dynamicBody;
    
    //ballBodyDef.position.Set(this->getPosition().x/SCALE_RATIO,this->getPosition().y/SCALE_RATIO);
    if(image != NULL)
        squareBodyDef.userData = image;
    
    this->body = _to->CreateBody(&squareBodyDef);
    fx = body->CreateFixture(&fixture);
    body->SetGravityScale(10);
}
void BPRectangle::setImage(const char *image){
    this->image = Sprite::create(image);
    this->addChild(this->image);
}

void BPRectangle::setOnRefresh(std::function<void ()> _set){
    this->onRefresh = _set;
}
void BPRectangle::BPSetPosition(cocos2d::Vec2 position){
    this->setPosition(Vec2(position.x, position.y));
    this->body->SetTransform(b2Vec2(position.x/SCALE_RATIO, position.y/SCALE_RATIO), this->body->GetAngle());
}
void BPRectangle::BPRotate(float angle){
    angle = angle * 0.0174532925;
    this->body->SetTransform(body->GetPosition(), angle);
    this->image->setRotation(angle);
}
void BPRectangle::BPScale(float scaleX, float scaleY){
    
}
b2Body* BPRectangle::BPGetBody(){
    return this->body;
}
Sprite* BPRectangle::BPGetSprite(){
    return this->image;
}
b2Fixture* BPRectangle::BPGetFixture(){
    return this->fx;
}
void BPRectangle::align(){
    this->setPosition(Vec2(body->GetPosition().x * SCALE_RATIO,body->GetPosition().y * SCALE_RATIO));
    this->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
}
void BPRectangle::refresh(){
    align();
    onRefresh();
}
void BPRectangle::setUserData(void *_userData){
    this->fixture.userData = _userData;
}