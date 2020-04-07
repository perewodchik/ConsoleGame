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
	std::shared_ptr<Creature> getCreatureByPosition(const Position& pos);
	std::vector<std::shared_ptr<Creature> > getCreatureVector();

	void drawMap();
private:
	std::vector<std::vector<std::shared_ptr<Creature> > > m_map;
	std::vector<std::unique_ptr<Player> >& m_players;
	
};

