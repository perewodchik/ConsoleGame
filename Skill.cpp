#include <Skill.h>

Skill::Skill()
{
	targetHelper_ = nullptr;
}

void Skill::setTargetHelper(ITargetHelper* targetHelper)
{
	targetHelper_ = targetHelper;
}