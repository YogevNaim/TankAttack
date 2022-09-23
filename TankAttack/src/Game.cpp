#include "Game.h"

Game::Game()
{
	m_sAppName = L"Tank Attack";

	if (ConstructConsole(m_WindowWidth, m_WindowHeight, m_FontSize, m_FontSize))
	{
		Start();
	}
	else
	{
		__debugbreak();
	}
}

Game::~Game()
{

}

bool Game::OnUserCreate()
{
	// TODO: Init

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Clear screen
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, 0);
	
	// Handle inputs
	HandlePlayerMoveInputs();

	// TODO: Update

	// TODO: Draw

	return true;
}

void Game::HandlePlayerMoveInputs()
{
	Vec2 input{};

	if (m_keys[VK_LEFT].bHeld)
	{
		input.m_X += -1.f;
	}

	if (m_keys[VK_RIGHT].bHeld)
	{
		input.m_X += 1.f;
	}

	if (m_keys[VK_UP].bHeld)
	{
		input.m_Y += -1.f;
	}

	if (m_keys[VK_DOWN].bHeld)
	{
		input.m_Y += 1.f;
	}

	// TODO: Move player
}
