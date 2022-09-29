#pragma once

#include "MovingObject.h"

class Tank;

class Projectile : public MovingObject
{
public:
	Projectile(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, Tank& owner, COLOUR color = COLOUR::FG_DARK_GREY, bool isAlive = true);
	~Projectile() {}

	virtual void OnCollision(Object& other, const Vec2& location) override;

protected:
	Tank* m_Owner;
};
