#include <UpgradeMenu.h>

UpgradeMenu::UpgradeMenu(std::vector< std::unique_ptr<Player> >& players,
	TargetController* targetController) :m_players(players)
{
	m_targetController = targetController;
}

void UpgradeMenu::run()
{
	system("cls");
	bool canUpgrade = true;
	for (int i = 0; i < m_players.size(); i++)
	{
		canUpgrade = false;
		for (auto creature : m_players[i]->getCreatures())
		{
			if (m_players[i]->getExp() >= creature->getMaxExp())
			{
				canUpgrade = true;
				std::cout << m_players[i]->getName()
					<< ", you have available upgrades!"
					<< "Do you want to proceed?\n"
					<< "[1]. Yes\n[2]. No\n";

				int intInput;
				std::cin >> intInput;
				if (intInput == 1)
					upgradePlayerCreatures(m_players[i]);
				break;
			}
		}

		if (!canUpgrade)
		{
			std::cout << m_players[i]->getName()
				<< ", you don't have any creatures to upgrade\n\n";
			system("pause");
		}

		//Helper loop for setting up necessary things
		for (auto creature : m_players[i]->getCreatures())
		{
			creature->setTeam(i + 1);
			for (auto skill : creature->getSkills())
			{
				skill->setTargetHelper(m_targetController);
				skill->setUser(creature);
			}
		}

		system("cls");
	}
}

void UpgradeMenu::upgradePlayerCreatures(std::unique_ptr<Player>& player)
{
	system("cls");

	bool canUpgrade = true;
	std::vector<std::shared_ptr<Creature> >& 
		playerCreatures = player->getCreaturesReference();

	while (canUpgrade)
	{
		std::vector<std::reference_wrapper<std::shared_ptr<Creature> > > upgradableCreatures;
		for (auto& creature : playerCreatures)
		{
			if ((creature->getMaxExp() <= player->getExp()) && creature->canBeUpgraded())
			{
				upgradableCreatures.push_back(creature);
			}
		}

		for(int i = 0; i < upgradableCreatures.size(); i++)
		{
			std::cout
				<< upgradableCreatures[i].get()->getName()
				<< " can be upgraded. Press <"
				<< i+1 << "> to upgrade it\n";
		}

		if (upgradableCreatures.size() == 0)
			break;

		std::cout << "\nPress <0> to save XP for later\n";

		int intInput;
		std::cin >> intInput;
		while (intInput < 0 || intInput > upgradableCreatures.size())
		{
			std::cout << "Please choose the correct action\n";
			std::cin >> intInput;
		}

		if (intInput == 0)
			break;

		int xpSpent = upgradeCreature(upgradableCreatures[intInput - 1], player->getExp());
		player->spendExp(xpSpent);
		for (auto cr : player->getCreatures())
		{
			std::cout << cr->getName();
			std::cout << "\n";
		}

		system("pause");

		
	}
}

int UpgradeMenu::upgradeCreature(
	std::shared_ptr<Creature>& creature, int availableExp)
{	
	system("cls");

	int xpRequired = creature->getMaxExp();
	std::string type = creature->getName();
	if (type == "Peasant")
	{
		std::cout
			<< "Peasant's available upgrades:\n"
			<< "== 1 == Archer\n"
			<< "== 2 == Knight\n"
			<< "== 3 == Spirit\n"
			<< "\n"
			<< "Upgrade requires spending "
			<< xpRequired << " xp\n"
			<< "You currently have " << availableExp << " xp\n"
			<< "\n"
			<< "Select which creature do you want to upgrade into\n"
			<< "Pres <0> to skip\n";

		int intInput = -1;
		std::cin >> intInput;
		while (intInput < 0 || intInput > 3) 
		{
			std::cout << "Please choose the correct action\n";
			std::cin >> intInput;
		}

		if (intInput == 0)
			return 0;

		switch (intInput)
		{
		case 1:
			creature = std::make_shared<Archer>();
			break;
		}
	}
	return xpRequired;
}