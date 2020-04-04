#include "Initializer.h"
#include <Config.h>
#include <Peasant.h>
#include <Archer.h>

Initializer::Initializer(std::vector<std::unique_ptr<Player> >& players):
	players_(players)
{
}

void Initializer::Initialize() {
	std::cout << "Welcome to the game!\n";
	std::string input;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		std::cout << "Enter name of player " << i << ": ";
		std::cin >> input;
		players_[i]->setName(input);

		std::cout << input << ", Now choose your characters\n";
		players_[i]->AddCreature(std::make_shared<Peasant>());
		players_[i]->AddCreature(std::make_shared<Archer>());
		players_[i]->AddCreature(std::make_shared<Peasant>());
		players_[i]->AddCreature(std::make_shared<Peasant>());

		for (auto hero : players_[i]->getCreatures())
		{
			hero->setTeam(i);
		}
	}
}