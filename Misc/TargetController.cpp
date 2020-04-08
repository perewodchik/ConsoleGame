#include <Misc/TargetController.h>
#include <iomanip>

TargetController::TargetController()
{
	m_map = nullptr;
}

std::vector<std::shared_ptr<Creature> > TargetController::showAvailableCreatures(const Position& pos, TYPE type)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}
	std::cout << "\n";
	int counter = 1;
	std::vector<std::shared_ptr<Creature> > creatures;
	for (auto creature : m_map->getCreatureVector())
	{
		if (creature == nullptr || creature->isDead())
			continue;

		//if type is friendly, i.e type = 1, then it switches to friendly creatures
		//else if type = 0, then looks for enemy creatures

		

		if ( type == TYPE::enemy && 
			m_map->getCreatureByPosition(pos)->getTeam() != creature->getTeam() 
		|| type == TYPE::friendly &&
			m_map->getCreatureByPosition(pos)->getTeam() == creature->getTeam())
		{
			std::cout << "#" << counter << ". "
				<< std::setw(12)
				<< creature->getName() << " "
				<< creature->getPosition() << " "
				<< std::setw(3)
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

std::shared_ptr<Creature> TargetController::getSingleTarget(const Position& pos, TYPE type)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: Map is not initialized";
		return nullptr;
	}

	std::cout << "\n";

	auto AvailableCreatures = this->showAvailableCreatures(pos, type);
	if (AvailableCreatures.size() == 0)
	{
		std::cout << "No available creatures\n";
		return nullptr;
	}

	std::cout << "\n";
	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > AvailableCreatures.size() )
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

	std::cout << "\n";

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
							<< std::setw(12) 
							<< targetCreature->getName() << " "
							<< targetCreature->getPosition() << " "
							<< std::setw(3)
							<< targetCreature->getHealth() << " HP, "
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
							<< std::setw(12)
							<< targetCreature->getName() << " "
							<< targetCreature->getPosition() << " "
							<< std::setw(3)
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

	std::cout << "\n";
	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > AvailableCreatures.size() + 1)
	{
		std::cout << "Incorrect value. Please type a creature from 1 to " << AvailableCreatures.size() + 1 << "\n";
		std::cin >> choice;
	}
	
	return AvailableCreatures[choice - 1];
}

std::vector< std::shared_ptr<Creature> > TargetController::getAll(const Position& pos, TYPE type)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}

	std::vector<std::shared_ptr<Creature> > creatures;
	for (auto creature : m_map->getCreatureVector())
	{
		if (creature == nullptr || creature->isDead())
			continue;

		if (type == TYPE::enemy &&
			m_map->getCreatureByPosition(pos)->getTeam() != creature->getTeam()
			|| type == TYPE::friendly &&
			m_map->getCreatureByPosition(pos)->getTeam() == creature->getTeam())
		{
			creatures.push_back(creature);
		}
	}
	return creatures;
}

std::shared_ptr<Creature> TargetController::getDeadAlly(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}
	int counter = 1;
	std::vector<std::shared_ptr<Creature> > AvailableCreatures;
	for (auto creature : m_map->getCreatureVector())
	{
		if (creature == nullptr)
			continue;

		if (m_map->getCreatureByPosition(pos)->getTeam() == creature->getTeam()
			&& m_map->getCreatureByPosition(pos)->isDead())
		{
			std::cout << "#" << counter << ". "
				<< std::setw(12)
				<< creature->getName() << " "
				<< creature->getPosition() << " "
				<< std::setw(3)
				<< creature->getHealth() << " HP,"
				<< creature->getArmor() << " ARMOR";
			if (creature->getIsDefending())
				std::cout << ", DEFENDING";
			std::cout << "\n";

			AvailableCreatures.push_back(creature);
			counter++;
		}
	}
	

	if (AvailableCreatures.size() == 0)
	{
		std::cout << "No available creatures\n";
		return nullptr;
	}

	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > AvailableCreatures.size())
	{
		std::cout << "Incorrect value. Please type a creature from 1 to " << AvailableCreatures.size() + 1 << "\n";
		std::cin >> choice;
	}

	return AvailableCreatures[choice - 1];
}

std::vector< std::shared_ptr<Creature> > TargetController::getEnemiesInLane(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}
	
	std::cout << "Choose a lane from 1 to " << BATTLEFIELD_WIDTH << "\n";

	int choice = -1;
	std::cin >> choice;
	while (choice <= 0 || choice > BATTLEFIELD_WIDTH )
	{
		std::cout << "Incorrect value. Please type a number from 1 to " << BATTLEFIELD_WIDTH << "\n";
		std::cin >> choice;
	}

	std::vector<std::shared_ptr<Creature> > targetCreatures;

	for (int h = 0; h < BATTLEFIELD_HEIGHT; h++)
	{
		auto targetCreature = m_map->getCreatureByCoordinates(h, choice-1);
		if (targetCreature->isDead())
			continue;

		if (targetCreature->getTeam() != m_map->getCreatureByPosition(pos)->getTeam())
		{
			targetCreatures.push_back(targetCreature);
		}
	}

	return targetCreatures;
}