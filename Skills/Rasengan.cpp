#include <Skills/Rasengan.h>

Rasengan::Rasengan(int damage) : Skill("Rasengan")
{
	m_damage = damage;
	m_spellName += " {" + std::to_string(m_damage) + "}";
}

void Rasengan::emit()
{
	auto user = m_user.lock();

	auto enemyTargets = m_targetHelper->getEnemiesInLane(user->getPosition());

	system("cls");

	for (auto target : enemyTargets)
	{
		int dmgTaken = target->takeDamage(m_damage);
		std::cout << target->getName() << " was hit with rasengan for "
			<< dmgTaken << " damage\n";
	}

}