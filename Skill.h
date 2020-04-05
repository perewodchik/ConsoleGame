#pragma once
#include <ITargetHelper.h>
#include <IUser.h>

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