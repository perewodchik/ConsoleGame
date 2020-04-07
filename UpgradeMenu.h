#pragma once
#include <vector>
#include <Player.h>
#include <TargetController.h>
#include <Windows.h>

class UpgradeMenu
{
public:
	UpgradeMenu(std::vector < std::unique_ptr<Player> >& players,
		TargetController* targetController);
	void run();
private:
	std::vector < std::unique_ptr<Player> >& m_players;
	TargetController* m_targetController;
};

