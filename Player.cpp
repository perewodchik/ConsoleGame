#pragma once
#include <Player.h>

Player::Player()
{
}

void Player::addCreature(std::shared_ptr<Creature> hero_sptr)
{
	m_creatures.push_back(hero_sptr);
}