#include <Skill.h>

Skill::Skill(std::string spellName)
{
	m_targetHelper = nullptr;
	m_spellName = spellName;
}

void Skill::setTargetHelper(ITargetHelper* targetHelper)
{
	m_targetHelper = targetHelper;
}

void Skill::setUser(std::shared_ptr<IUser> user)
{
	m_user = user;
}
