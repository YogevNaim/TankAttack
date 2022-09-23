#pragma once

#include "utils/Math.h"

class Object
{
public:
	Object();
	Object(Vec2 location, Vec2 velocity, Vec2 size, bool isAlive = true);
	~Object();

	virtual Vec2 GetLocation() const { return m_Location; }
	virtual Vec2 GetVelocity() const { return m_Velocity; }
	virtual bool GetIsAlive() const { return m_IsAlive; }

	virtual bool OnUserUpdate(float fElapsedTime) = 0;
	virtual void SetLocation(const Vec2& location);

protected:
	Vec2 m_Location;
	Vec2 m_Velocity;
	Vec2 m_Size;
	bool m_IsAlive;
};

