#include <Battlefield.h>
#include <TargetController.h>

Battlefield::Battlefield(std::vector<std::unique_ptr<Player> >& players)
	:players_(players), map_(std::make_unique<Map>(players))
{
	std::cout << "Starting the battle!\n";
}

void Battlefield::run()
{
	
	map_->drawMap();
	TargetController targetController_(std::move(map_));
	int hp = targetController_.getSingleEnemyTarget(Position(0, 0))->getCurrentHp();
	std::cout << "Your chosen creature's hp is " << hp << std::endl;
}