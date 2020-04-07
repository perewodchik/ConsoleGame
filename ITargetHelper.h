#pragma once
#include <Position.h>

class Creature;

class ITargetHelper
{
public:
	enum type { friendly = 0, enemy = 1 };

	virtual std::shared_ptr<Creature> getSingleTarget(const Position& pos, bool friendly) = 0;
	virtual std::shared_ptr<Creature> getSingleEnemyTargetMelee(const Position& pos) = 0;
	virtual std::shared_ptr<Creature> getSelf(const Position& pos) = 0;

};

