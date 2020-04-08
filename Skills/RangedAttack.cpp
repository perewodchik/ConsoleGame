#include <Skills/RangedAttack.h>


RangedAttack::RangedAttack(int damage) : Skill("Ranged Attack")
{
	m_damage = damage;
	m_spellName += " {" + std::to_string(m_damage) + "}";
}

void RangedAttack::emit()
{
	auto user = m_user.lock();

	auto enemyTarget = m_targetHelper->getSingleTarget(
		user->getPosition(),  ITargetHelper::TYPE::enemy);

	system("cls");

	if (dice_rand() < enemyTarget->getEvasion())
	{
		std::cout << enemyTarget->getName()
			<< " has evaded the attack\n";
		return;
	}

	int dmgTaken = enemyTarget->takeDamage(m_damage);
	std::cout << "enemy took " << dmgTaken << " damage\n";
}