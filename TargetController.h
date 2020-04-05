#pragma once
#include <ITargetHelper.h>
#include <Map.h>
class TargetController : public ITargetHelper
{
public:
	TargetController();
	void setMap(Map* map) { m_map = map; };
	std::vector<std::shared_ptr<Creature> > showAvailableEnemyCreatures(const Position& pos);

	//ITargetHelper methods
	virtual std::shared_ptr<Creature> getSingleEnemyTarget(const Position& pos);
	virtual std::shared_ptr<Creature> getSelf(const Position& pos);
private:
	Map* m_map;
};

