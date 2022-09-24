#include "Game.h"

#include "classes/Tank.h"

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
	// Init
	ResetGame();

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// Clear screen
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, 0);
	
	// Handle inputs
	if (!m_Player.expired())
	{
		HandlePlayerMoveInputs();
	}

	// Update
	for (auto object : m_Objects)
	{
		object->OnUserUpdate(fElapsedTime);
	}

	// Draw
	for (auto object : m_Objects)
	{
		object->Draw();
	}

	return true;
}

void Game::HandlePlayerMoveInputs()
{
	Vec2 input{};
	// Single axis input
	if (m_keys[VK_LEFT].bHeld)
	{
		input.m_X += -1.f;
	}
	else if (m_keys[VK_RIGHT].bHeld)
	{
		input.m_X += 1.f;
	}
	else if (m_keys[VK_UP].bHeld)
	{
		input.m_Y += -1.f;
	}
	else if (m_keys[VK_DOWN].bHeld)
	{
		input.m_Y += 1.f;
	}
	
	auto player = m_Player.lock();
	player->SetVelocity(input);
}

void Game::ResetGame()
{
	// This will also destroy the player reference since it's a weak_ptr
	m_Objects.clear();

	// Spawn new player
	std::shared_ptr<Tank> newPlayer = std::make_shared<Tank>(*this, Vec2{ScreenWidth() / 2.f, ScreenHeight() / 2.f}, Vec2{0.f, 0.f}, Vec2{6.f, 6.f}, ObjectType::PLAYER ,COLOUR::FG_CYAN);
	m_Objects.push_back(newPlayer);
	m_Player = newPlayer;

	// Spawn borders
	std::shared_ptr<Object> leftBorder = std::make_shared<Object>(*this, Vec2{ 1.f ,ScreenHeight() / 2.f }, Vec2{ 0.f, 0.f }, Vec2{ 2.f,  (float)ScreenHeight() }, ObjectType::BORDER, COLOUR::FG_GREY);
	m_Objects.push_back(leftBorder);
	std::shared_ptr<Object> rightBorder = std::make_shared<Object>(*this, Vec2{ (float)ScreenWidth() -1.f ,ScreenHeight() / 2.f }, Vec2{ 0.f, 0.f }, Vec2{ 2.f,  (float)ScreenHeight() }, ObjectType::BORDER, COLOUR::FG_GREY);
	m_Objects.push_back(rightBorder);
	std::shared_ptr<Object> topBorder = std::make_shared<Object>(*this, Vec2{ (float)ScreenWidth() / 2.f ,1.f }, Vec2{ 0.f, 0.f }, Vec2{ (float)ScreenWidth(),  2.f }, ObjectType::BORDER, COLOUR::FG_GREY);
	m_Objects.push_back(topBorder);
	std::shared_ptr<Object> BottomBorder = std::make_shared<Object>(*this, Vec2{ (float)ScreenWidth() / 2.f ,(float)ScreenHeight() -1.f }, Vec2{ 0.f, 0.f }, Vec2{ (float)ScreenWidth(),  2.f }, ObjectType::BORDER, COLOUR::FG_GREY);
	m_Objects.push_back(BottomBorder);
}
