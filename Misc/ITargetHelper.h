#pragma once
#include <Misc/Position.h>
#include <vector>

class Creature;

class ITargetHelper
{
public:
	virtual ~ITargetHelper() {};
	enum  class TYPE { enemy, friendly };

	virtual std::shared_ptr<Creature> getSingleTarget(const Position& pos, TYPE type) = 0;
	virtual std::shared_ptr<Creature> getSingleEnemyTargetMelee(const Position& pos) = 0;
	virtual std::shared_ptr<Creature> getSelf(const Position& pos) = 0;
	virtual std::shared_ptr<Creature> getDeadAlly(const Position& pos) = 0;
	virtual std::vector< std::shared_ptr<Creature> > getAll(const Position& pos, TYPE type) = 0;
	virtual std::vector< std::shared_ptr<Creature> > getEnemiesInLane(const Position& pos) = 0;

};

