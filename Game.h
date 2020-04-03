#pragma once
#include <iostream>
#include <vector>
#include <Player.h>
#include <Config.h>

class Game {
public:
	Game();
	bool isRunning() const { return isRunning_; };
	void update();
private:
	std::vector < std::unique_ptr<Player> > players_;
	enum STATE { INIT, MENU, UPGRADE, BATTLE, EXIT };
	int curState;
	bool isRunning_;
};