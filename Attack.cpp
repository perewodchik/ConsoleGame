#include <Attack.h>
#include <Creature.h>
void Attack::emit(IUser* user)
{	
	std::shared_ptr<Creature> enemyTarget = 
		targetHelper_->getSingleEnemyTarget(user->getPosition());
	enemyTarget->takeDamage(25);
	std::cout << "enemy took 25 damage\n";
}