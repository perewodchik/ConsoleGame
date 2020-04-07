#include <Skills/Heal.h>
#include <Creatures/Creature.h>

Heal::Heal(int heal) : Skill("Heal ally")
{
	m_heal = heal;
}

void Heal::emit()
{
	auto user = m_user.lock();
	auto friendlyTarget =
		m_targetHelper->getSingleTarget(
			user->getPosition(), ITargetHelper::friendly);
	int healed = friendlyTarget->receiveHeal(m_heal);
		std::cout << friendlyTarget->getName()
		<< " was healed for "
		<< healed << " hp\n";
}