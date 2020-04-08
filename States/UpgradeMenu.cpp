#include <States/UpgradeMenu.h>

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
					<< " Do you want to proceed?\n\n"
					<< "<1>. Upgrade\n<2>. Skip\n\n";

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
			if ((creature->getMaxExp() <= player->getExp()) && creature->getUpgrades().size() != 0)
			{
				upgradableCreatures.push_back(creature);
			}
		}

		for(int i = 0; i < upgradableCreatures.size(); i++)
		{
			std::cout
				<< "<" << i + 1 << "> Upgrade "
				<< upgradableCreatures[i].get()->getName()
				<< "\n";
		}

		if (upgradableCreatures.size() == 0)
			break;

		std::cout << "\n<0> Save XP for later\n\n";

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

		std::cout << "\n";
		system("pause");
		system("cls");
	}
}

int UpgradeMenu::upgradeCreature(
	std::shared_ptr<Creature>& creature, int availableExp)
{
	system("cls");

	int xpRequired = creature->getMaxExp();
	std::string type = creature->getName();

	auto upgrades = creature->getUpgrades();

	if (upgrades.size() == 0)
	{
		std::cout << "There are no possible upgrades\n";
		return 0;
	}
	
	std::vector<std::shared_ptr<Creature> > creatureUpgradesVector;

	std::cout << creature->getName() << "'s available upgrades\n";

	int counter = 0;
	for (auto upgradeClass : upgrades)
	{
		std::cout << "<" << counter+1 << "> " << creature->getName() << " -> ";
		if (upgradeClass == Creature::CLASS::Archer)
		{
			creatureUpgradesVector.push_back(std::make_shared<Archer>());
		}
		if (upgradeClass == Creature::CLASS::Knight)
		{
			creatureUpgradesVector.push_back(std::make_shared<Knight>());
		}
		if (upgradeClass == Creature::CLASS::Spirit)
		{
			creatureUpgradesVector.push_back(std::make_shared<Spirit>());
		}
		if (upgradeClass == Creature::CLASS::Priest)
		{
			creatureUpgradesVector.push_back(std::make_shared<Priest>());
		}
		if (upgradeClass == Creature::CLASS::Warlock)
		{
			creatureUpgradesVector.push_back(std::make_shared<Warlock>());
		}
		if (upgradeClass == Creature::CLASS::Shinobi)
		{
			creatureUpgradesVector.push_back(std::make_shared<Shinobi>());
		}
		if (upgradeClass == Creature::CLASS::Anduin)
		{
			creatureUpgradesVector.push_back(std::make_shared<Anduin>());
		}
		if (upgradeClass == Creature::CLASS::Naruto)
		{
			creatureUpgradesVector.push_back(std::make_shared<Naruto>());
		}
		if (upgradeClass == Creature::CLASS::Hanzo)
		{
			creatureUpgradesVector.push_back(std::make_shared<Hanzo>());
		}
		if (upgradeClass == Creature::CLASS::Paladin)
		{
			creatureUpgradesVector.push_back(std::make_shared<Paladin>());
		}

		std::cout << creatureUpgradesVector[counter]->getName() << " : "
			<< creatureUpgradesVector[counter]->getMaxHealth() << " hp, "
			<< creatureUpgradesVector[counter]->getArmor() << " armor, "
			<< creatureUpgradesVector[counter]->getInitiative() << " initiative\n";
		for (auto skill : creatureUpgradesVector[counter]->getSkills())
		{
			std::cout << "   + " << skill->getSpellName() << "\n";
		}

		counter++;
	}
	std::cout << "\n";

	int intInput = -1;
	std::cin >> intInput;
	while (intInput < 0 || intInput > creatureUpgradesVector.size())
	{
		std::cout << "Please choose the correct action\n";
		std::cin >> intInput;
	}

	if (intInput == 0)
		return 0;

	std::cout << creature->getName() << " has been upgraded into ";
	creature = creatureUpgradesVector.at(intInput - 1);
	std::cout << creature->getName() << "\n";

	return xpRequired;
}