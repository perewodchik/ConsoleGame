#include <Battlefield.h>
#include <TargetController.h>

Battlefield::Battlefield(std::vector<std::unique_ptr<Player> >& players)
	:players_(players)
{
	map_ = std::make_shared<Map>(players);
	targetController_ = std::make_shared<TargetController>(map_);
	for (int i = 0; i < players_.size(); i++)
	{
		auto creatures = players_[i]->getCreatures();
		for (int j = 0; j < creatures.size(); j++)
		{
			creatures[j]->setTargetHelperForSkill(targetController_);
		}
	}
	std::cout << "Starting the battle!\n";
}

void Battlefield::run()
{

	map_->drawMap();
	
	auto creature = map_->getCreatureByCoordinates(0, 1);
	std::cout << creature->getAssociatedTag() << " is casting a skill\n";
	creature->castSkill();
}