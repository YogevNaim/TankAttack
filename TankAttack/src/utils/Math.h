#pragma once

struct Vec2
{
	Vec2()
		: m_X(0.f), m_Y(0.f) {}

	Vec2(float x, float y)
		: m_X(x), m_Y(y) {}

	bool operator==(const Vec2& other)
	{
		return m_X == other.m_X && m_Y == other.m_Y;
	}

	Vec2 operator+(const Vec2& other)
	{
		return Vec2{m_X + other.m_X, m_Y + other.m_Y };
	}

	Vec2 operator-(const Vec2& other)
	{
		return Vec2{ m_X - other.m_X, m_Y - other.m_Y };
	}

	Vec2 operator*(const float& other)
	{
		return Vec2{ m_X * other, m_Y * other };
	}

	Vec2 Dot(const Vec2& other)
	{
		return Vec2{ m_X * other.m_X, m_Y * other.m_Y };
	}


	float m_X, m_Y;
};

