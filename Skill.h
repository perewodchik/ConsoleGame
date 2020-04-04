#pragma once
#include <ITargetHelper.h>
#include <IUser.h>
class Skill
{
public:
	Skill() {};
	virtual void emit() {};
private:
	std::weak_ptr<ITargetHelper> targetHelper_;
	std::weak_ptr<IUser> user_;
};

