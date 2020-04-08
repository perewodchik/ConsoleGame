#include <States/Initializer.h>
#include <Config.h>
#include <Creatures/BaseTier/Peasant.h>
#include <Creatures/BaseTier/Apprentice.h>
#include <Creatures/BaseTier/Assassin.h>
#include <string>

Initializer::Initializer(std::vector<std::unique_ptr<Player> >& players,
	TargetController* targetController)
	:m_players(players)
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

		std::cout << strInput << ", choose your characters:\n\n"
			<< "+---+------------+----+-------+-------------+-----------------+------------+\n"
			<< "| # |    CLASS   | HP | ARMOR | EXP_UPGRADE | EXP_WHEN_KILLED | INITIATIVE |\n"
			<< "+---+------------+----+-------+-------------+-----------------+------------+\n"
			<< "| 1 |    PEASANT | 45 |  10   |      40     |        15       |     15     |\n"
			<< "| 2 |   ASSASSIN | 35 |  15   |      50     |        40       |     35     |\n"
			<< "| 3 | APPRENTICE | 50 |   0   |      30     |        25       |     10     |\n"
			<< "+---+------------+----+-------+-------------+-----------------+------------+\n\n";
		
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
				std::cout << "You have added assassin\n";
				m_players[i]->addCreature(std::make_shared<Assassin>());
				characters_selected++;
				break;
			case 3:
				std::cout << "You have added apprentice\n";
				m_players[i]->addCreature(std::make_shared<Apprentice>());
				characters_selected++;
				break;

			default:
				std::cout << "There is no such character. Please try again\n";
				break;
			}
			
		}
		
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

		std::cout << "\n";
		system("pause");
		system("cls");
	}
	
}