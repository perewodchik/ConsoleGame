#include <Skills/Skill.h>

Skill::Skill(std::string spellName):
	seed(time(0)),
	dice_rand(std::bind(std::uniform_int_distribution<int>(0, 100),
		std::mt19937(seed)))
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
