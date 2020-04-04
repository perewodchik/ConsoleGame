#pragma once
#include <ITargetHelper.h>
#include <IUser.h>

class Skill
{
public:
	Skill();
	void setTargetHelper(ITargetHelper* targetHelper);
	virtual void emit(IUser* user) {};
protected:
	ITargetHelper* targetHelper_;
};