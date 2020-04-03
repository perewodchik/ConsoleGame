#include <Battlefield.h>

Battlefield::Battlefield(std::vector<std::unique_ptr<Player> >& players)
	:players_(players), map_(Map(players))
{
}

void Battlefield::run()
{
	std::cout << "Starting the battle!\n";
	map_.drawMap();
	while (true)
	{
		std::cin;
	}
}