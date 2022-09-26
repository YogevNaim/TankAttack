#include "Object.h"

#include "olcConsoleGameEngine.h"

Object::Object(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, COLOUR color, bool isAlive)
	: m_Game(&game), m_Location(location), m_Velocity(velocity), m_Size(size), m_Type(type), m_Color(color), m_IsAlive(isAlive) {}

Object::~Object()
{
}

void Object::Draw()
{
	Game* game = GetGameRef();
	if (game)
	{
 		game->Fill((int)m_Location.m_X - (int)m_Size.m_X / 2, (int)m_Location.m_Y - (int)m_Size.m_Y / 2,
			(int)m_Location.m_X + (int)m_Size.m_X / 2, (int)m_Location.m_Y + (int)m_Size.m_Y / 2,
			(wchar_t)PIXEL_TYPE::PIXEL_SOLID, (short)m_Color);
	}
}

void Object::SetVelocity(const Vec2& velocity)
{
	m_Velocity = velocity;
}

bool Object::SquareObjectCollision(Object& A, Object& B, const Vec2& location)
{
	if ((int)location.m_X + (int)A.GetSize().m_X / 2 > (int)B.GetLocation().m_X - (int)B.GetSize().m_X / 2 &&
		(int)location.m_X - (int)A.GetSize().m_X / 2 < (int)B.GetLocation().m_X + (int)B.GetSize().m_X / 2 &&
		(int)location.m_Y + (int)A.GetSize().m_Y / 2 > (int)B.GetLocation().m_Y - (int)B.GetSize().m_Y / 2 &&
		(int)location.m_Y - (int)A.GetSize().m_Y / 2 < (int)B.GetLocation().m_Y + (int)B.GetSize().m_Y / 2)
	{
		A.OnCollision(B, location);
		B.OnCollision(A, location);
		return true;
	}
	return false;
}

void Object::OnCollision(Object& other, const Vec2& location)
{
}

void Object::SetLocation(const Vec2& location)
{
	m_Location = location;
}
