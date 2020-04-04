#include <Skill.h>

Skill::Skill()
{
	targetHelper_ = nullptr;
}

void Skill::setTargetHelper(std::shared_ptr<ITargetHelper> targetHelper)
{
	targetHelper_ = targetHelper;
}