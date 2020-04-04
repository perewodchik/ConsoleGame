#pragma once
#include <Player.h>

Player::Player()
{
}

void Player::AddCreature(std::shared_ptr<Creature> hero_sptr)
{
	creatures_.push_back(hero_sptr);
}