#pragma once
#include <ITargetHelper.h>
#include <IUser.h>

class Skill
{
public:
	Skill();
	void setTargetHelper(std::shared_ptr<ITargetHelper> targetHelper);
	virtual void emit(IUser* user) {};
protected:
	std::shared_ptr<ITargetHelper> targetHelper_;
};

