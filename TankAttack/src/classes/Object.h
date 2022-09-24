#pragma once

#include <memory>

#include "Game.h"

class Object
{
public:
	Object(Game& game, Vec2 location, Vec2 velocity, Vec2 size, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	~Object();

	virtual void Draw();

	virtual Vec2 GetLocation() const { return m_Location; }
	virtual Vec2 GetVelocity() const { return m_Velocity; }
	virtual bool GetIsAlive() const { return m_IsAlive; }

	virtual bool OnUserUpdate(float fElapsedTime) = 0;
	virtual void SetLocation(const Vec2& location);
	virtual void SetVelocity(const Vec2& velocity);

protected:
	Game* GetGameRef() const { return m_Game; }

	Vec2 m_Location;
	Vec2 m_Velocity;
	float m_SpeedMultiplier = 25.f;
	Vec2 m_Size;
	COLOUR m_Color;
	bool m_IsAlive;

	Game* m_Game;
};
