#pragma once
#include <Creature.h>
#include <Position.h>
class ITargetHelper
{
	virtual std::shared_ptr<Creature> getSingleEnemyTarget(const Position& pos) = 0;
};

