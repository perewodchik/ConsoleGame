#pragma once
#include <vector>
#include <memory>
#include <Player.h>
#include <Misc/Map.h>
#include <Misc/TargetController.h>
#include <algorithm>
#include <iomanip>

class Battlefield
{
public:
	Battlefield(std::vector<std::unique_ptr<Player> >& players,
		TargetController* TargetController);
	~Battlefield() { delete m_map; };
	void run();
private:
	Map* m_map;
	int m_findWinner();
	std::vector<std::unique_ptr<Player> >& m_players;
	std::vector<std::shared_ptr<Creature> > m_creaturesOrder;
};

