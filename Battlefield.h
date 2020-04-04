#pragma once
#include <vector>
#include <memory>
#include <queue>
#include <Player.h>
#include <Map.h>
#include <TargetController.h>

class Battlefield
{
public:
	Battlefield(std::vector<std::unique_ptr<Player> >& players);
	void run();
private:
	std::vector<std::unique_ptr<Player> >& players_;
	std::unique_ptr<Map> map_;

	std::queue<std::shared_ptr<Creature> > queue_;
};
