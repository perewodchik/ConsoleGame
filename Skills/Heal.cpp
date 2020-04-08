#include <Skills/Heal.h>
#include <Creatures/Creature.h>

Heal::Heal(int heal) : Skill("Heal ally")
{
	m_heal = heal;
	m_spellName += " {" + std::to_string(m_heal) + "}";
}

void Heal::emit()
{
	auto user = m_user.lock();
	auto friendlyTarget =
		m_targetHelper->getSingleTarget(
			user->getPosition(), ITargetHelper::TYPE::friendly);

	system("cls");

	int healed = friendlyTarget->receiveHeal(m_heal);
		std::cout << friendlyTarget->getName()
		<< " was healed for "
		<< healed << " hp\n";
}