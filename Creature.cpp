#include <Creature.h>

Creature::Creature(int hp, int armor, int initiative, int maxExp, int killExp, char tag)
{
	isProtected_ = false;
	curExperience_ = 0;
	hp_ = hp;
	maxHp_ = hp;
	armor_ = armor;
	maxExperience_ = maxExp;
	killExperience_ = killExp;
	initiative_ = initiative;
	associatedTag_ = tag;
	team_ = -1;
	skill_ = std::make_unique<Skill>();
}

void Creature::receiveHeal(int value)
{
	hp_ += value;
	if (hp_ >= maxHp_)
	{
		hp_ = maxHp_;
	}
}

void Creature::takeDamage(int value)
{
	if (isProtected_)
		value /= 2;
	value *= 1 - armor_ / 100.0;
	hp_ -= value;
}

void Creature::addExperience(int value)
{
	curExperience_ += value;
	if (curExperience_ > maxExperience_)
	{
		curExperience_ = maxExperience_;
	}
}

void Creature::setTeam(int team)
{
	team_ = team;
}

void Creature::setPosition(Position pos)
{
	pos_ = pos;
}

void Creature::setTargetHelperForSkill(std::shared_ptr<ITargetHelper> targetHelper)
{
	skill_->setTargetHelper(targetHelper);
}

void Creature::castSkill()
{
	skill_->emit(this);
}