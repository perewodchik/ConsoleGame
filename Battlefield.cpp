#include <Battlefield.h>
#include <TargetController.h>

Battlefield::Battlefield(std::vector<std::unique_ptr<Player> >& players, TargetController* targetController)
	:m_players(players)
{
	m_map = new Map(m_players);
	targetController->setMap(m_map);

	m_creaturesOrder = m_map->getCreatureVector();
	std::sort(m_creaturesOrder.begin(), m_creaturesOrder.end(),
		[](const std::shared_ptr<Creature>& a,
			const std::shared_ptr<Creature>& b) -> bool
		{
			return a->getInitiative() > b->getInitiative();
		});

	std::cout << "Starting the battle!\n";
}

int Battlefield::m_findWinner()
{
	int winner = 0;
	bool flag = false;
	for (auto creature : m_creaturesOrder)
	{
		if (winner == creature->getTeam())
			continue;

		if (!flag)
		{
			flag = true;
			winner = creature->getTeam();
		}
		else
		{
			return 0;
		}
	}
	return winner;
}

void Battlefield::run()
{
	while (!m_findWinner())
	{
		/*
			Player chooses skill
			Skill resolves
			Removing dead creatures, changing order
		*/

		m_map->drawMap();


		std::cout << "Order: ";
		for (auto creature : m_creaturesOrder) 
			std::cout << creature->getTag() << " ";
		std::cout << "\n\n";

		auto creature = m_creaturesOrder[0];
		std::cout
			<< m_players[creature->getTeam() - 1]->getName()
			<< " @ " << creature->getName()
			<< " HP=" << creature->getHealth()
			<< ", ARMOR=" << creature->getArmor()
			<< ", DEF=" << creature->getIsDefending()
			<< ", POS=" << creature->getPosition()
			<< "\n";

		auto skills = creature->getSkills();
		for (int i = 0; i < skills.size(); i++)
		{
			std::cout 
					<< ">> "
					<< std::setw(12) << std::left
					<< skills[i]->getSpellName()
					<< "[" << i+1 << "]\n";
		}

		std::cout << "\n\n.. Show Advanced Map [0]\n";
		
		int numInput;
		std::cin >> numInput;
		while (numInput < 0 || numInput > skills.size())
			std::cout << "Please select the correct action\n";
		
		if (numInput == 0)
		{
			std::cout << "You have chose adv map, but it doesn't work yet\n";
			continue;
		}
		
		skills[numInput-1]->emit();

		


	}
}