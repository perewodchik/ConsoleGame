#include <Skills/Defend.h>
#include <Creatures/Creature.h>

Defend::Defend() : Skill("Defend")
{
}

void Defend::emit()
{
	auto user = m_user.lock();
	auto self = m_targetHelper->getSelf(user->getPosition());
	self->startDefending();
}