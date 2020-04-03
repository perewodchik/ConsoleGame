#pragma once
#include <vector>
#include <memory>
#include <Player.h>
#include <Config.h>

class Map
{
public:
	Map(std::vector<std::unique_ptr<Player> >& players);
	std::shared_ptr<Creature> getCreatureByCoordinates(int h, int w);
	void drawMap();
private:
	std::vector<std::vector<std::shared_ptr<Creature> > > map_;
	std::vector<std::unique_ptr<Player> >& players_;
	
};

