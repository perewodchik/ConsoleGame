#pragma once
#include <Windows.h>
#include <vector>
#include <Player.h>
#include <TargetController.h>
#include <Archer.h>

class UpgradeMenu
{
public:
	UpgradeMenu(std::vector < std::unique_ptr<Player> >& players,
		TargetController* targetController);
	void run();
private:
	std::vector < std::unique_ptr<Player> >& m_players;
	TargetController* m_targetController;
	void upgradePlayerCreatures(std::unique_ptr<Player>& player);
	int upgradeCreature(std::shared_ptr<Creature>& creature, int availableExp);
};

