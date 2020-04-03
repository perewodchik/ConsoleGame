#pragma once
#include <Skill.h>
#include <iostream>
class Defend : public Skill
{
	void emit() override {
		std::cout << "I am defending\n";
	};
};

