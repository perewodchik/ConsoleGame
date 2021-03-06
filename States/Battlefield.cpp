#include <States/Battlefield.h>
#include <Misc/TargetController.h>

Battlefield::Battlefield(std::vector<std::unique_ptr<Player> >& players, TargetController* targetController)
	:m_players(players)
{
	m_map = new Map(m_players);
	targetController->setMap(m_map);

	//Sorting by initiative
	m_creaturesOrder = m_map->getCreatureVector();
	std::sort(m_creaturesOrder.begin(), m_creaturesOrder.end(),
		[](const std::shared_ptr<Creature>& a,
			const std::shared_ptr<Creature>& b) -> bool
		{
			return a->getInitiative() > b->getInitiative();
		});

	//Setting creature to battling state
	for (auto creature : m_creaturesOrder)
	{
		if (creature->isDead())
		{
			creature->setIsDead(false);
		}
		creature->receiveHeal(1000);
	}

	std::cout << "Starting the battle!\n";
}

int Battlefield::m_findWinner()
{
	int winner = 0;
	bool flag = false;

	//In case of draw, player 1 still wins
	if (m_creaturesOrder.size() == 0)
		return 1;

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
		std::cout << "Order: ";
		for (auto creature : m_creaturesOrder)
		{
			if (creature->isDead() == true)
				continue;
			std::cout << creature->getTag() << " ";
		}
		std::cout << "\n";
		m_map->drawMap();
		std::cout << "\n";

		//Finding first alive creature to take turn
		int iDeadCheck = 0;
		auto currentCreature = m_creaturesOrder[iDeadCheck];
		while (currentCreature->isDead() == true) {
			iDeadCheck++;
			currentCreature = m_creaturesOrder[iDeadCheck];
		}

		if (currentCreature->getIsDefending() == true) {
			currentCreature->stopDefending();
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
					<< std::setw(20) << std::left
					<< skills[i]->getSpellName()
					<< "[" << i+1 << "]\n";
		}
		std::cout << "\n";

		int numInput;
		std::cin >> numInput;
		while (numInput <= 0 || numInput > skills.size())
		{
			std::cout << "Please select the correct action\n";
			std::cin >> numInput;
		}
					
		system("cls");

		//Entering skill casting menu
		m_map->drawMap();
		skills[numInput-1]->emit();

		//Handling after-spell state
		//i.e checking for dead people,
		//changing turn order
		for (int i = 0; i < m_creaturesOrder.size(); i++)
		{
			auto creature = m_creaturesOrder[i];
			if (creature->getHealth() <= 0 && !creature->isDead())
			{
				std::cout 
					<< creature->getName()
					<< " at position " << creature->getPosition()
					<< " has died\n";
				creature->setIsDead(true);

				m_players[currentCreature->getTeam() - 1]->addExp(creature->getKillExp());
				std::cout 
					<< m_players[currentCreature->getTeam() - 1]->getName()
					<< " has received " << creature->getKillExp() << " experience\n";
			}
		}
		m_creaturesOrder.push_back(currentCreature);
		m_creaturesOrder.erase(m_creaturesOrder.begin()+iDeadCheck);
		
		std::cout << "\n";
		system("pause");
		system("cls");
	}

	std::cout << m_players[m_findWinner()-1]->getName() << " has won the round!\n\n";
	for (int i = 0; i < m_players.size(); i++)
	{
		std::cout << m_players[i]->getName() << " currently has "
			<< m_players[i]->getExp() << " experience\n";
	}
	
	std::cout << "\n";
	system("pause");
}