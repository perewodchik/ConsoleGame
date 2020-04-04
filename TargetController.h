#pragma once
#include <ITargetHelper.h>
#include <Map.h>
class TargetController : public ITargetHelper
{
public:
	TargetController();
	TargetController(std::unique_ptr<Map> map_);
	void setMap(std::unique_ptr<Map> map) { map_ = std::move(map); };
	std::vector<std::shared_ptr<Creature> > showAvailableEnemyCreatures(const Position& pos);
	virtual std::shared_ptr<Creature> getSingleEnemyTarget(const Position& pos);
private:
	std::unique_ptr<Map> map_;
};

