#pragma once
#include <iostream>
#include <Creature.h>
#include <vector>
class Player {
public:
	Player();
	void AddCreature(std::shared_ptr<Creature> creature_sptr);
	std::string getName() const { return name_; };
	void setName(std::string name) { name_ = name; };
	std::vector<std::shared_ptr<Creature> > getCreatures() { return creatures_; };
private:
	std::string name_;
	std::vector<std::shared_ptr<Creature> > creatures_;
};