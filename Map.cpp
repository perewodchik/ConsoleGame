#include <Map.h>

Map::Map(std::vector<std::unique_ptr<Player> >& players)
	: m_players(players)
{
	m_map.resize(BATTLEFIELD_HEIGHT);
	for (int i = 0; i < m_map.size(); i++)
		m_map[i].resize(BATTLEFIELD_WIDTH);

	int current_row = 0;
	int current_column = 0;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		for (auto creature : m_players[i]->getCreatures())
		{
			if (current_column >= BATTLEFIELD_WIDTH) 
			{
				current_column = 0;
				current_row++;
			}
			if (current_row >= BATTLEFIELD_HEIGHT)
			{
				std::cout << "There's not enough space on the battlefield\n";
				throw "Not enough space";
			}

			m_map[current_row][current_column] = creature;
			creature->setPosition(Position(current_row, current_column));
			current_column++;
		}
	}
}

std::shared_ptr<Creature> Map::getCreatureByCoordinates(int h, int w)
{
	if (h >= BATTLEFIELD_HEIGHT || w >= BATTLEFIELD_WIDTH)
		return nullptr;
	return m_map[h][w];
}

std::shared_ptr<Creature> Map::getCreatureByPosition(const Position& pos)
{
	if (pos.getH() >= BATTLEFIELD_HEIGHT || pos.getW() >= BATTLEFIELD_WIDTH)
		return nullptr;
	return m_map[pos.getH()][pos.getW()];
}

std::vector<std::shared_ptr<Creature> > Map::getCreatureVector()
{
	std::vector<std::shared_ptr<Creature> > creatures;
	for (auto row : m_map)
	{
		for (auto creature : row)
		{
			creatures.push_back(creature);
		}
	}
	return creatures;
}

void Map::drawMap()
{
	"Drawing map\n";
	for (int h = 0; h < BATTLEFIELD_HEIGHT; h++)
	{
		if (h % 2 == 0)
			std::cout << "+---+---+\n";
		for (int w = 0; w < BATTLEFIELD_WIDTH; w++)
		{
			auto creature = this->getCreatureByCoordinates(h, w);
			if (creature == nullptr || creature->isDead())
			{
				std::cout << "| . ";
			}
			else
			{
				std::cout << "| " << 
					creature->getTag() << " ";
			}
			
		}
		std::cout << "|\n";
	}
	std::cout << "+---+---+\n";
}

void Map::removeFromMap(const Position& pos)
{
	m_map[pos.getH()][pos.getW()] = nullptr;
}