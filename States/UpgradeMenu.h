#pragma once
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <Player.h>
#include <Misc/TargetController.h>
#include <Creatures/MiddleTier/Archer.h>
#include <Creatures/MiddleTier/Knight.h>
#include <Creatures/MiddleTier/Spirit.h>
#include <Creatures/MiddleTier/Priest.h>
#include <Creatures/MiddleTier/Warlock.h>
#include <Creatures/MiddleTier/Shinobi.h>
#include <Creatures/HighTier/Anduin.h>
#include <Creatures/HighTier/Naruto.h>
#include <Creatures/HighTier/Hanzo.h>
#include <Creatures/HighTier/Paladin.h>

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

