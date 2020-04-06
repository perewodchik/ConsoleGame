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

		if (creature->isDead() || winner == creature->getTeam())
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

		m_map->drawMap();
		std::cout << "Order: ";
		for (auto creature : m_creaturesOrder)
		{
			if (creature->isDead() == true)
				continue;
			std::cout << creature->getTag() << " ";
		}
			
		std::cout << "\n\n";

		
		int iDeadCheck = 0;
		auto currentCreature = m_creaturesOrder[iDeadCheck];
		while (currentCreature->isDead() == true) {
			iDeadCheck++;
			currentCreature = m_creaturesOrder[iDeadCheck];
		}

		std::cout
			<< m_players[currentCreature->getTeam() - 1]->getName()
			<< " @ " << currentCreature->getName()
			<< " HP=" << currentCreature->getHealth()
			<< ", ARMOR=" << currentCreature->getArmor()
			<< ", DEF=" << currentCreature->getIsDefending()
			<< ", POS=" << currentCreature->getPosition()
			<< "\n";

		auto skills = currentCreature->getSkills();
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
			std::cout << "You have chosen adv map, but it doesn't work yet\n";
			continue;
		}
		

		system("cls");
		m_map->drawMap();
		skills[numInput-1]->emit();

		for (int i = 0; i < m_creaturesOrder.size(); i++)
		{
			auto creature = m_creaturesOrder[i];
			if (creature->getHealth() <= 0 && !creature->isDead())
			{
				std::cout << creature->getName()
					<< " at position " << creature->getPosition()
					<< " has died\n";
				creature->setIsDead(true);
			}
		}
		m_creaturesOrder.push_back(currentCreature);
		
		system("pause");
		system("cls");
	}
	std::cout << m_players[m_findWinner()-1]->getName() << ", you have won!";
	int a;
	std::cin >> a;
}