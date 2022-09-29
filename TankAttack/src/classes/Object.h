#pragma once

#include "Game.h"

enum class ObjectType
{
	NONE = 0,
	BORDER,
	PLAYER,
	PROJECTILE,
	ENEMY
};

class Object
{
public:
	Object(Game& game, Vec2 location, Vec2 velocity, Vec2 size, ObjectType type, COLOUR color = COLOUR::FG_WHITE, bool isAlive = true);
	virtual ~Object();

	virtual void Draw();

	ObjectType GetType() const { return m_Type; };
	virtual Vec2 GetLocation() const { return m_Location; }
	virtual Vec2 GetVelocity() const { return m_Velocity; }
	virtual Vec2 GetSize() const { return m_Size; }
	virtual bool GetIsAlive() const { return m_IsAlive; }

	virtual bool OnUserUpdate(float fElapsedTime) { return true; }
	virtual void SetLocation(const Vec2& location);
	virtual void SetVelocity(const Vec2& velocity);
	virtual void SetIsAlive(const bool isAlive) { m_IsAlive = isAlive; }
	
	static bool SquareObjectCollision(Object& A, Object& B, const Vec2& location);
	virtual void OnCollision(Object& other,const Vec2& location);

protected:
	Game* GetGameRef() const { return m_Game; }
	float GetSpeedMultiplier() const { return m_SpeedMultiplier; }

private:
	ObjectType m_Type;
	Vec2 m_Location;
	Vec2 m_Velocity;
	float m_SpeedMultiplier = 25.f;
	Vec2 m_Size;
	COLOUR m_Color;
	bool m_IsAlive;

	Game* m_Game;
};
