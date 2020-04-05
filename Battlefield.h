#pragma once
#include <vector>
#include <memory>
#include <Player.h>
#include <Map.h>
#include <TargetController.h>
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
	std::vector<std::unique_ptr<Player> >& m_players;
	Map* m_map;
	std::vector<std::shared_ptr<Creature> > m_creaturesOrder;
	int m_findWinner();
};

