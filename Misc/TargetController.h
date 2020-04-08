#pragma once
#include <Misc/ITargetHelper.h>
#include <Misc/Map.h>
class TargetController : public ITargetHelper
{
public:
	TargetController();
	void setMap(Map* map) { m_map = map; };
	std::vector<std::shared_ptr<Creature> > showAvailableCreatures(const Position& pos, TYPE type);

	
	//ITargetHelper methods
	virtual std::shared_ptr<Creature> getSingleTarget(const Position& pos, TYPE type);
	virtual std::shared_ptr<Creature> getSingleEnemyTargetMelee(const Position& pos);
	virtual std::shared_ptr<Creature> getSelf(const Position& pos);
	virtual std::shared_ptr<Creature> getDeadAlly(const Position& pos);
	virtual std::vector< std::shared_ptr<Creature> > getAll(const Position& pos, TYPE type);
	virtual std::vector< std::shared_ptr<Creature> > getEnemiesInLane(const Position& pos);
private:
	Map* m_map;
};

