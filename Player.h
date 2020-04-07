#pragma once
#include <iostream>
#include <Creature.h>
#include <vector>
class Player {
public:
	Player();
	int getWins() const { return m_wins; };
	int getExp() const { return m_exp; };
	std::string getName() const { return m_name; };

	void addWin();
	void addExp(int value);
	void spendExp(int value);
	void setName(std::string name) { m_name = name; };
	void addCreature(std::shared_ptr<Creature> creature_sptr);
	std::vector<std::shared_ptr<Creature> > getCreatures() { return m_creatures; };
private:
	std::string m_name;
	std::vector<std::shared_ptr<Creature> > m_creatures;

	int m_wins;
	int m_exp;
};