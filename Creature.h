#pragma once
#include <Skill.h>
#include <vector>
#include <memory>
class Creature
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
	void emitSkill() const { skill_->emit(); };

	void takeDamage(int value);
	void receiveHeal(int value);
	void addExperience(int value);

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
protected:
	std::unique_ptr<Skill> skill_;
};

