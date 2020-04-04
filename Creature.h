#pragma once
#include <vector>
#include <Position.h>
#include <memory>
#include <IUser.h>
class Creature : IUser
{
public:
	Creature(int hp, int armor, int initiative, int maxExp, int killExp, char tag);
	~Creature() = default;

	int getCurrentHp() const { return hp_; };
	int getMaxHp() const { return maxHp_; };
	int getArmor() const { return armor_; };
	int getExperience() const { return curExperience_; };
	int getKillExperience() const { return killExperience_; };
	char getAssociatedTag() const { return  associatedTag_; };

	void takeDamage(int value);
	void receiveHeal(int value);
	void addExperience(int value);

	int getTeam() { return team_; };
	Position getPosition() { return pos_; };
	void setTeam(int team);
	void setPosition(Position pos);

private:
	bool isProtected_;
	int hp_;
	int maxHp_;
	int armor_;
	int initiative_;
	int curExperience_;
	int maxExperience_;
	int killExperience_;
	char associatedTag_;

	int team_;
	Position pos_;
};

