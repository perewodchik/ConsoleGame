#pragma once
#include <Misc/ITargetHelper.h>
#include <Misc/IUser.h>
#include <string>
#include <memory>

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
};