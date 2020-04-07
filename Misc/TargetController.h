#pragma once
#include <Misc/ITargetHelper.h>
#include <Misc/Map.h>
class TargetController : public ITargetHelper
{
public:
	TargetController();
	void setMap(Map* map) { m_map = map; };
	std::vector<std::shared_ptr<Creature> > showAvailableCreatures(const Position& pos, bool friendly);

	
	//ITargetHelper methods
	virtual std::shared_ptr<Creature> getSingleTarget(const Position& pos, bool friendly);
	virtual std::shared_ptr<Creature> getSingleEnemyTargetMelee(const Position& pos);
	virtual std::shared_ptr<Creature> getSelf(const Position& pos);
private:
	Map* m_map;
};
