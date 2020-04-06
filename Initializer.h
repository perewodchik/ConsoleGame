#pragma once
#include <vector>
#include <Player.h>
#include <TargetController.h>
#include <Windows.h>

class Initializer
{
public:
	Initializer(std::vector<std::unique_ptr<Player> >& players,
		TargetController* targetController);
	void Initialize();
private:
	std::vector < std::unique_ptr<Player> >& m_players;
	TargetController* m_targetController;
};

