#include"include/box2d/box2d.h"
#include <iostream>

#

int main() {
    // Worldの重力を設定（下方向に9.8m/s^2）
    b2Vec2 gravity(0.0f, -9.8f);
    b2World world(gravity);

    // 地面（静的なオブジェクト）を作成
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // 動的なボディ（物体）を作成
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    // シミュレーションステップ
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        std::cout << "Step " << i << ": (" << position.x << ", " << position.y << "), angle: " << angle << std::endl;
    }

    return 0;
}
