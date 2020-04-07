#include <TargetController.h>

TargetController::TargetController()
{
	m_map = nullptr;
}

std::vector<std::shared_ptr<Creature> > TargetController::showAvailableCreatures(const Position& pos, bool friendly)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}
	int counter = 1;
	std::vector<std::shared_ptr<Creature> > creatures;
	for (auto creature : m_map->getCreatureVector())
	{
		if (creature == nullptr || creature->isDead())
			continue;

		if (friendly ^ (m_map->getCreatureByPosition(pos)->getTeam() != creature->getTeam()))
		{
			std::cout << "#" << counter << ". "
				<< creature->getName() << " "
				<< creature->getPosition() << " "
				<< creature->getHealth() << " HP,"
				<< creature->getArmor() << " ARMOR";
			if (creature->getIsDefending())
				std::cout << ", DEFENDING";
			std::cout << "\n";

			creatures.push_back(creature);
			counter++;
		}
	}
	return creatures;
}

std::shared_ptr<Creature> TargetController::getSingleTarget(const Position& pos, bool friendly)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: Map is not initialized";
		return nullptr;
	}

	auto AvailableCreatures = this->showAvailableCreatures(pos, friendly);
	if (AvailableCreatures.size() == 0)
	{
		std::cout << "No available creatures\n";
		return nullptr;
	}
	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > AvailableCreatures.size() + 1)
	{
		std::cout << "Incorrect value. Please type a creature from 1 to " << AvailableCreatures.size() + 1 << "\n";
		std::cin >> choice;
	}
	return AvailableCreatures[choice - 1];
}

std::shared_ptr<Creature> TargetController::getSelf(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: Map is not initialized";
		return nullptr;
	}

	return m_map->getCreatureByPosition(pos);
}


std::shared_ptr<Creature> TargetController::getSingleEnemyTargetMelee(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: Map is not initialized";
		return nullptr;
	}

	std::vector< std::shared_ptr<Creature> > AvailableCreatures;

	int h = pos.getH();
	int w = pos.getW();
	int counter = 0;
	auto creature = m_map->getCreatureByPosition(pos);

	//Assuming HEIGHT is even
	if (h < BATTLEFIELD_HEIGHT / 2)
	{
		//it goes down, we must check row with h = 2
		//if they are dead, he can attack row h = 3
		bool isAllRowDead = true;
		for (int i = BATTLEFIELD_HEIGHT / 2; i < BATTLEFIELD_HEIGHT; i++)
		{
			if (!isAllRowDead)
				break;

			for (int j = 0; j < BATTLEFIELD_WIDTH; j++)
			{
				auto targetCreature = m_map->getCreatureByCoordinates(i, j);
				if (creature->getTeam() != targetCreature->getTeam())
				{
					if (!targetCreature->isDead())
					{
						isAllRowDead = false;
						AvailableCreatures.push_back(targetCreature);

						std::cout << "#" << counter+1 << ". "
							<< targetCreature->getName() << " "
							<< targetCreature->getPosition() << " "
							<< targetCreature->getHealth() << " HP,"
							<< targetCreature->getArmor() << " ARMOR";
						if (targetCreature->getIsDefending())
							std::cout << ", DEFENDING";
						std::cout << "\n";
						counter++;
					}
				}
			}
		}
	}
	else
	{
		//it goes up, we must check row with h = 1
		//if they are dead, he can attack row h = 0
		//...
		bool isAllRowDead = true;
		for (int i = BATTLEFIELD_HEIGHT / 2 - 1; i >= 0; i--)
		{
			if (!isAllRowDead)
				break;

			for (int j = 0; j < BATTLEFIELD_WIDTH; j++)
			{
				auto targetCreature = m_map->getCreatureByCoordinates(i, j);
				if (creature->getTeam() != targetCreature->getTeam())
				{
					if (!targetCreature->isDead())
					{
						isAllRowDead = false;
						AvailableCreatures.push_back(targetCreature);

						std::cout << "#" << counter + 1 << ". "
							<< targetCreature->getName() << " "
							<< targetCreature->getPosition() << " "
							<< targetCreature->getHealth() << " HP,"
							<< targetCreature->getArmor() << " ARMOR";
						if (targetCreature->getIsDefending())
							std::cout << ", DEFENDING";
						std::cout << "\n";
						counter++;
					}
				}
			}
		}
	}

	if (AvailableCreatures.size() == 0)
	{
		std::cout << "No available creatures\n";
		return nullptr;
	}
	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > AvailableCreatures.size() + 1)
	{
		std::cout << "Incorrect value. Please type a creature from 1 to " << AvailableCreatures.size() + 1 << "\n";
		std::cin >> choice;
	}
	return AvailableCreatures[choice - 1];
}