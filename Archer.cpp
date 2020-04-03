#include <Archer.h>
#include <Defend.h>


Archer::Archer() : Creature(50, 0, 70, 100, 40, 'A')
{
	skill_ = std::make_unique<Defend>();
}