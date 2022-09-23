#include "Game.h"

Game::Game()
{
	ConstructConsole(m_WindowWidth, m_WindowHeight, m_FontSize, m_FontSize);
	Start();
}

Game::~Game()
{

}

bool Game::OnUserCreate()
{
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	return true;
}
