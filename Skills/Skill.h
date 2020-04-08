#pragma once
#include <Misc/ITargetHelper.h>
#include <Misc/IUser.h>
#include <string>
#include <memory>
#include <random>
#include <ctime>
#include <functional>

class Skill
{
public:
	Skill(std::string spellName);
	void setTargetHelper(ITargetHelper* targetHelper);
	void setUser(std::shared_ptr<IUser> user);
	std::string getSpellName() { return m_spellName; };

	virtual void emit() {};
protected:
	ITargetHelper* m_targetHelper;
	std::string m_spellName;
	std::weak_ptr<IUser> m_user;
	std::mt19937::result_type seed;
	std::_Binder<std::_Unforced, std::uniform_int_distribution<int>, std::mt19937> dice_rand;
};