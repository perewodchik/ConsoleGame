#include <Skills/GiveDefend.h>
#include <Creatures/Creature.h>

GiveDefend::GiveDefend() : Skill("Give Defend")
{
}

void GiveDefend::emit()
{
	auto user = m_user.lock();
	auto target = m_targetHelper->getSingleTarget(user->getPosition(), ITargetHelper::TYPE::friendly);
	target->startDefending();

	system("cls");
	std::cout << target->getName() << " is now defending\n";
}