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
	~Battlefield() { delete targetController_; };
	void run();
private:
	std::vector<std::unique_ptr<Player> >& players_;
	std::shared_ptr<Map> map_;
	ITargetHelper* targetController_;
	std::queue<std::shared_ptr<Creature> > queue_;
};

