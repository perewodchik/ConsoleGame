#pragma once
#include <Position.h>

class Creature;

class ITargetHelper
{
public:
	virtual std::shared_ptr<Creature> getSingleEnemyTarget(const Position& pos) = 0;
	virtual std::shared_ptr<Creature> getSelf(const Position& pos) = 0;
};

