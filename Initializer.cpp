#include "Initializer.h"
#include <Config.h>
#include <Peasant.h>
#include <Archer.h>
#include <string>

Initializer::Initializer(std::vector<std::unique_ptr<Player> >& players,
	TargetController* targetController):
	m_players(players)
{
	m_targetController = targetController;
}

void Initializer::run() {
	std::cout << "Welcome to the game!\n";
	std::string strInput;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		std::cout << "Enter name of player " << i+1 << ": ";
		std::cin >> strInput;
		m_players[i]->setName(strInput);

		system("cls");

		std::cout << strInput << ", choose your characters:\n"
			<< "+---+---------+----+-------+---------+----------+------------+\n"
			<< "| # |  CLASS  | HP | ARMOR | MAX_EXP | EXP_KILL | INITIATIVE |\n"
			<< "+---+---------+----+-------+---------+----------+------------+\n"
			<< "| 1 | PEASANT | 25 |   0   |    30   |    10    |     0      |\n"
			<< "| 2 |  ARCHER | 50 |   0   |   100   |    40    |    70      |\n"
			<< "| 3 |  NARUTO | 80 |  20   |    60   |    80    |    75      |\n"
			<< "+---+---------+----+-------+---------+----------+------------+\n";
		
		int characters_selected = 0;
		int numInput;
		while (characters_selected < 4)
		{
			std::cin >> numInput;
			
			switch (numInput)
			{
			case 1:
				std::cout << "You have added peasant\n";
				m_players[i]->addCreature(std::make_shared<Peasant>());
				characters_selected++;
				break;
			case 2:
				std::cout << "You have added archer\n";
				m_players[i]->addCreature(std::make_shared<Archer>());
				characters_selected++;
				break;
			default:
				std::cout << "There is no such character. Please try again\n";
				break;
			}
			
		}

		m_players[i]->addExp(40);
		

		//Helper loop for setting up necessary things
		for (auto creature : m_players[i]->getCreatures())
		{
			creature->setTeam(i+1);
			for (auto skill : creature->getSkills())
			{
				skill->setTargetHelper(m_targetController);
				skill->setUser(creature);
			}
		}


		system("pause");
		system("cls");
	}
	
}