#pragma once
#include <iostream>
#include <Creature.h>
#include <vector>
class Player {
public:
	Player();
	void addCreature(std::shared_ptr<Creature> creature_sptr);
	std::string getName() const { return m_name; };
	void setName(std::string name) { m_name = name; };
	std::vector<std::shared_ptr<Creature> > getCreatures() { return m_creatures; };
private:
	std::string m_name;
	std::vector<std::shared_ptr<Creature> > m_creatures;
};