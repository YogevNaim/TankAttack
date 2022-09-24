#include "Tank.h"
#include <algorithm>

Tank::Tank(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, COLOUR color, bool isAlive)
	: Pawn(game, location, velocity, size, type, color, isAlive) {}

void Tank::Draw()
{
	// Draw body
	Pawn::Draw();
	
	// Draw turret
	Game* game = GetGameRef();
	if (game)
	{
		Vec2 turretEndLocation = m_FwdVector * 6.f + m_Location;

   		int x1 = std::min<int>((int)m_Location.m_X - 1, (int)turretEndLocation.m_X + 1);
		int x2 = std::max<int>((int)m_Location.m_X + 1, (int)turretEndLocation.m_X - 1);
		int y1 = std::min<int>((int)m_Location.m_Y - 1, (int)turretEndLocation.m_Y + 1);
		int y2 = std::max<int>((int)m_Location.m_Y + 1, (int)turretEndLocation.m_Y - 1);
		
		game->Fill(x1, y1, x2, y2, (wchar_t)PIXEL_TYPE::PIXEL_SOLID);
	}
}

void Tank::UpdateMovement(float fElapsedTime)
{
	Pawn::UpdateMovement(fElapsedTime);
	if (m_Velocity.m_X != 0.f || m_Velocity.m_Y != 0.f)
	{
		m_FwdVector = m_Velocity;
	}
}
