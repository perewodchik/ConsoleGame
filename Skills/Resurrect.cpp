#include "Resurrect.h"

Resurrect::Resurrect() : Skill("Resurrect")
{
	m_used = false;
}

void Resurrect::emit()
{
	auto user = m_user.lock();

	system("cls");

	if (m_used)
	{
		std::cout << "You have already used this skill\n";
		return;
	}

	std::cout << "You can only cast this skill once per battle!\n";
	m_used = true;

	auto allyTarget = m_targetHelper->getDeadAlly(user->getPosition());
	allyTarget->setIsDead(false);
	allyTarget->receiveHeal(1000);

	std::cout << allyTarget->getName() << " has been resurrected\n";

	m_spellName += "{USED}";
}