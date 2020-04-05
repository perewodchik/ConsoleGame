#include <TargetController.h>

TargetController::TargetController()
{
	m_map = nullptr;
}

std::vector<std::shared_ptr<Creature> > TargetController::showAvailableEnemyCreatures(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: map is not initialized\n";
		return {};
	}
	int counter = 1;
	std::vector<std::shared_ptr<Creature> > creatures;
	std::cout << "+---+------------+---------------+----------+\n";
	for (auto creature : m_map->getCreatureVector())
	{
		if (m_map->getCreatureByPosition(pos)->getTeam() != creature->getTeam())
		{
			std::cout << "| " << counter << " | ";
			std::cout << " TAG = [" << creature->getTag() << "] | ";
			std::cout << " POS = " << creature->getPosition() << " | ";
			std::cout << " HP = " << creature->getHealth() << " |\n";

			creatures.push_back(creature);
			counter++;
		}
	}
	std::cout << "+---+------------+---------------+----------+\n";
	return creatures;
}

std::shared_ptr<Creature> TargetController::getSingleEnemyTarget(const Position& pos)
{
	if (m_map == nullptr)
	{
		std::cout << "[ERROR]: Map is not initialized";
		return nullptr;
	}

	auto AvailableCreatures = this->showAvailableEnemyCreatures(pos);
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