#include "Object.h"

Object::Object()
	: m_Location(0.f, 0.f), m_Velocity(0.f, 0.f), m_Size(10.f, 10.f), m_IsAlive(false) {}

Object::Object(Vec2 location, Vec2 velocity, Vec2 size, bool isAlive)
	: m_Location(location), m_Velocity(velocity), m_Size(size), m_IsAlive(isAlive) {}

Object::~Object()
{
}

void Object::SetLocation(const Vec2& location)
{
	m_Location = location;
}
