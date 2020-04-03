#pragma once
#include <iostream>
#include <Creature.h>
#include <vector>
class Player {
public:
	Player();
	void AddHero(std::shared_ptr<Creature> hero_sptr);
	std::string getName() const { return name_; };
	void setName(std::string name) { name_ = name; };
	std::vector<std::shared_ptr<Creature> > getHeroes() { return heroes_; };
private:
	std::string name_;
	std::vector<std::shared_ptr<Creature> > heroes_;
};