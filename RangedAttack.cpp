#include <RangedAttack.h>
#include <Creature.h>

RangedAttack::RangedAttack(int damage) : Skill("Ranged Attack")
{
	m_damage = damage;
}

void RangedAttack::emit()
{
	auto user = m_user.lock();
	auto enemyTarget = m_targetHelper->getSingleTarget(
		user->getPosition(),  ITargetHelper::friendly);
	int dmgTaken = enemyTarget->takeDamage(m_damage);
	std::cout << "enemy took " << dmgTaken << " damage\n";
}