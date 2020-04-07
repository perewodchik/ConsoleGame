#pragma once
#include <Player.h>

Player::Player()
{
	m_wins = 0;
	m_exp = 0;
}

void Player::addCreature(std::shared_ptr<Creature> hero_sptr)
{
	m_creatures.push_back(hero_sptr);
}

void Player::addWin()
{
	m_wins++;
}

void Player::addExp(int value)
{
	m_exp += value;
}

void Player::spendExp(int value)
{
	m_exp -= value;
}
