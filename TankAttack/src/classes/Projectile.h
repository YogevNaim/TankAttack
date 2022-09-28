#pragma once

#include "MovingObject.h"

class Projectile : public MovingObject
{
public:
	Projectile(Game& game, Vec2 location, Vec2 velocity, Vec2 size = Vec2{1.f, 1.f}, ObjectType type = ObjectType::PROJECTILE, Vec2 fwdVec = Vec2{2.f, 2.f}, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Projectile() {}

	virtual void OnCollision(Object& other, const Vec2& location) override;
};
