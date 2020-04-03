#include <Game.h>
#include <Initializer.h>
#include <Battlefield.h>

Game::Game() {
	isRunning_ = true;
	curState = INIT;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		players_.push_back(std::make_unique<Player>());
	}
}

void Game::update() {
	switch (curState) 
	{
		case INIT:
		{
			Initializer initializer(players_);
			initializer.Initialize();
			curState = BATTLE;
			break;
		}
		case BATTLE:
		{
			Battlefield battlefield(players_);
			battlefield.run();
		}
	}
	
}