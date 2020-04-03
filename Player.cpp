#pragma once
#include <Player.h>

Player::Player()
{
}

void Player::AddHero(std::shared_ptr<Creature> hero_sptr)
{
	heroes_.push_back(hero_sptr);
}