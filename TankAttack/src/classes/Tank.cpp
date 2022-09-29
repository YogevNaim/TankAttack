#include "Tank.h"
#include <algorithm>

Tank::Tank(Game& game, unsigned int id, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, Vec2 fwdVec, COLOUR color, bool isAlive)
	: MovingObject(game, location, velocity, size, type, fwdVec, color, isAlive), m_id(id) {}

void Tank::Draw()
{
	if (!GetIsAlive()) return;

	// Draw body
	MovingObject::Draw();
	
	// Draw turret
	Game* game = GetGameRef();
	if (game)
	{
		Vec2 location = GetLocation();
		Vec2 turretEndLocation = GetFwdVector() * 6.f + location;

   		int x1 = std::min<int>((int)location.m_X - 1, (int)turretEndLocation.m_X + 1);
		int x2 = std::max<int>((int)location.m_X + 1, (int)turretEndLocation.m_X - 1);
		int y1 = std::min<int>((int)location.m_Y - 1, (int)turretEndLocation.m_Y + 1);
		int y2 = std::max<int>((int)location.m_Y + 1, (int)turretEndLocation.m_Y - 1);
		
		game->Fill(x1, y1, x2, y2, (wchar_t)PIXEL_TYPE::PIXEL_SOLID);
	}
}

bool Tank::OnUserUpdate(float fElapsedTime)
{
	UpdateCanShoot(fElapsedTime);

	return MovingObject::OnUserUpdate(fElapsedTime);
}

void Tank::OnCollision(Object& other, const Vec2& location)
{
	// TODO: Collision response
}

void Tank::Shoot()
{
	m_LastShoot = 0.f;
	Game* game = GetGameRef();
	if (game)
	{
		game->SpawnProjectile(*this);
	}
}

void Tank::UpdateCanShoot(float fElapsedTime)
{
	m_LastShoot += fElapsedTime;
	m_CanShoot = m_LastShoot - m_ShootInterval >= 0;
}
