#pragma once
#include <vector>
#include <Player.h>
class Initializer
{
public:
	Initializer(std::vector<std::unique_ptr<Player> >& players);
	void Initialize();
private:
	std::vector < std::unique_ptr<Player> >& players_;
};

