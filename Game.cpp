#include <Game.h>
#include <Initializer.h>
#include <Battlefield.h>

Game::Game() {
	m_isRunning = true;
	m_curState = INIT;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		m_players.push_back(std::make_unique<Player>());
	}
	m_targetController = new TargetController;
}

void Game::run() {
	while (m_isRunning)
	{
		switch (m_curState)
		{
			case INIT:
			{
				Initializer initializer(m_players, m_targetController);
				initializer.Initialize();
				m_curState = BATTLE;
				break;
			}
			case BATTLE:
			{
				Battlefield battlefield(m_players, m_targetController);
				battlefield.run();
				break;
			}
		}
	}
}