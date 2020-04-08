#include <Skills/HealAll.h>
#include <Creatures/Creature.h>

HealAll::HealAll(int heal) : Skill("Heall all")
{
	m_heal = heal;
	m_spellName += " {" + std::to_string(m_heal) + "}";
}

void HealAll::emit()
{
	system("cls");
	auto user = m_user.lock();
	auto targets = m_targetHelper->getAll(
		user->getPosition(), ITargetHelper::TYPE::friendly);
	for (auto& target : targets) {
		int healed = target->receiveHeal(m_heal);
		std::cout << target->getName()
			<< " was healed for " << healed << " hp\n";
	}
}
