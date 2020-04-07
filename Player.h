#pragma once
#include <iostream>
#include <Creatures/Creature.h>
#include <vector>
class Player {
public:
	Player();

	//Getter methods
	int getWins        () const { return m_wins; };
	int getExp         () const { return m_exp;  };
	std::string getName() const { return m_name; };
	std::vector<std::shared_ptr<Creature> > 
		getCreatures() { return m_creatures; };

	//Solution for upgrading creatures
	std::vector<std::shared_ptr<Creature> >& 
		getCreaturesReference() { return m_creatures; };

	void addWin();
	void addExp(int value);
	void spendExp(int value);
	void setName(std::string name);
	void addCreature(std::shared_ptr<Creature> creature_sptr);
	
private:
	std::string m_name;
	std::vector<std::shared_ptr<Creature> > m_creatures;

	int m_wins;
	int m_exp;
};