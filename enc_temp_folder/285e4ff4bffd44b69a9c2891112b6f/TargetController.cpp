#include <TargetController.h>

TargetController::TargetController()
{
	map_ = nullptr;
}

TargetController::TargetController(std::unique_ptr<Map> map) : map_(std::move(map))
{

}

std::vector<std::shared_ptr<Creature> > TargetController::showAvailableEnemyCreatures(const Position& pos)
{
	if (map_ == nullptr)
	{
		std::cout << "Map is not initialized";
		return {};
	}
	int counter = 1;
	std::vector<std::shared_ptr<Creature> > creatures;
	std::cout << "+---+------------+---------------+----------+\n";
	for (auto row : map_->getVectorMap())
	{
		for (auto creature : row)
		{
			// +---+-----------+-------------+---------+
			// | 1 | TAG = [A] | POS = (1,1) | HP = 10 |
			// | 2 | TAG = [P] | POS = (1,2) | HP = 25 |
			// +---+-----------+-------------+---------+
				
			if (map_->getCreatureByPosition(pos)->getTeam() != creature->getTeam())
			{
				std::cout << "| " << counter << " | ";
				std::cout << " TAG = [" << creature->getAssociatedTag() << "] | ";
				std::cout << " POS = " << creature->getPosition() << " | " ;
				std::cout << " HP = " << creature->getCurrentHp() << " |\n";

				creatures.push_back(creature);
				counter++;
			}
			
		}
		
	}
	std::cout << "+---+------------+---------------+----------+\n";
	return creatures;
}

std::shared_ptr<Creature> TargetController::getSingleEnemyTarget(const Position& pos)
{
	if (map_ == nullptr)
	{
		std::cout << "Map is not initialized";
		return nullptr;
	}
	else
	{
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
}
