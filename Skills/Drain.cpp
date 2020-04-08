#include <Skills/Drain.h>

Drain::Drain(int damage) : Skill("Drain")
{
	m_damage = damage;
	m_spellName += " {" + std::to_string(m_damage) + "}";
}

void Drain::emit()
{
	auto user = m_user.lock();
	auto enemyTarget = m_targetHelper->getSingleTarget(
		user->getPosition(), ITargetHelper::TYPE::enemy);

	if (dice_rand() < enemyTarget->getEvasion())
	{
		std::cout << enemyTarget->getName()
			<< " has evaded the attack\n";
		return;
	}

	int dmgTaken = enemyTarget->takeDamage(m_damage);
	int healReceive = m_targetHelper->getSelf(user->getPosition())->receiveHeal(dmgTaken);
	std::cout << m_targetHelper->getSelf(user->getPosition())->getName() 
		<< " has dealt " << dmgTaken
		<< "to " << enemyTarget->getName() << " and healed himself for "
		<< healReceive << " hp\n";
}