#include <Skills/SplitArrows.h>

SplitArrows::SplitArrows(int damage, int shots, int missChance) : Skill("Split Arrows")
{
	m_damage = damage;
	m_shots = shots;
	m_missChance = missChance;
	m_spellName += " {" + std::to_string(m_damage) + "x" + std::to_string(shots) + "}";
}

void SplitArrows::emit()
{
	auto user = m_user.lock();

	for (int i = 0; i < m_shots; i++)
	{
		std::cout << "Shooting arrow {" << i << "} out of " << m_shots << "\n";

		auto enemyTarget = m_targetHelper->getSingleTarget(
			user->getPosition(), ITargetHelper::TYPE::enemy);
	
		if (dice_rand() < m_missChance)
		{
			std::cout << "Miss!\n";
			continue;
		}

		if (dice_rand() < enemyTarget->getEvasion())
		{
			std::cout << enemyTarget->getName()
				<< " has evaded the attack\n";
			return;
		}

		int dmgTaken = enemyTarget->takeDamage(m_damage);
		std::cout << "enemy took " << dmgTaken << " damage\n";

 	}

}