#include "Object.h"

#include "olcConsoleGameEngine.h"

Object::Object(Game& game, Vec2 location, Vec2 velocity, Vec2 size, COLOUR color, bool isAlive)
	: m_Game(&game), m_Location(location), m_Velocity(velocity), m_Size(size),m_Color(color), m_IsAlive(isAlive) {}

Object::~Object()
{
}

void Object::Draw()
{
	Game* game = GetGameRef();
	if (game)
	{
 		game->Fill(m_Location.m_X - m_Size.m_X / 2, m_Location.m_Y - m_Size.m_Y / 2, m_Location.m_X + m_Size.m_X / 2, m_Location.m_Y + m_Size.m_Y / 2, (wchar_t)PIXEL_TYPE::PIXEL_SOLID, (short)m_Color);
	}
}

void Object::SetVelocity(const Vec2& velocity)
{
	m_Velocity = velocity;
}

void Object::SetLocation(const Vec2& location)
{
	m_Location = location;
}
