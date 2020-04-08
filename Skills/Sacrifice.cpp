#include <Skills/Sacrifice.h>

Sacrifice::Sacrifice(int armor) : Skill("Sacrifice")
{
	m_armor = armor;
}

void Sacrifice::emit()
{
	auto user = m_user.lock();
	auto targets = m_targetHelper->getAll(
		user->getPosition(), ITargetHelper::TYPE::friendly);

	system("cls");

	for (auto& target : targets) {
		std::cout << target->getName()
			<< " has received " << target->receiveArmor(m_armor)
			<< " armor and defend\n";
		target->startDefending();
	}
	auto sacrificer = m_targetHelper->getSelf(user->getPosition());
	sacrificer->setIsDead(true);
}
