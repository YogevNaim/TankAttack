#include "Projectile.h"

Projectile::Projectile(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, COLOUR color, bool isAlive)
	: MovingObject(game, location, velocity, size, type, fwdVec, color, isAlive) {}

void Projectile::OnCollision(Object& other, const Vec2& location)
{
	// TODO: Collision response
}
