#include "Projectile.h"

#include "Tank.h"

Projectile::Projectile(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, Tank& owner, COLOUR color, bool isAlive)
	: MovingObject(game, location, velocity, size, type, fwdVec, color, isAlive), m_Owner(&owner) {}

void Projectile::OnCollision(Object& other, const Vec2& location)
{
	if (other.GetType() == ObjectType::BORDER)
	{
		SetIsAlive(false);
	}

	if (other.GetType() == ObjectType::ENEMY)
	{
		other.SetIsAlive(false);
		SetIsAlive(false);
	}

}
