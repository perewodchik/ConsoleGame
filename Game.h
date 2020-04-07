#pragma once
#include <iostream>
#include <vector>
#include <Player.h>
#include <Config.h>
#include <Misc/TargetController.h>

class Game {
public:
	Game();
	~Game() { delete m_targetController; };

	void run();
	bool isRunning() const { return m_isRunning; };
	
	enum STATE { INIT, MENU, UPGRADE, BATTLE, EXIT };
private:
	std::vector <std::unique_ptr<Player> > m_players;
	TargetController* m_targetController;
	int  m_curState;
	bool m_isRunning;
};