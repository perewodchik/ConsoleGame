#include <Map.h>

Map::Map(std::vector<std::unique_ptr<Player> >& players)
	: players_(players)
{
	map_.resize(BATTLEFIELD_HEIGHT);
	for (int i = 0; i < map_.size(); i++)
		map_[i].resize(BATTLEFIELD_WIDTH);

	int current_row = 0;
	int current_column = 0;
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		for (auto creature : players_[i]->getCreatures())
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

			map_[current_row][current_column] = creature;
			creature->setPosition(Position(current_row, current_column));
			current_column++;
		}
	}
}

std::shared_ptr<Creature> Map::getCreatureByCoordinates(int h, int w)
{
	if (h >= BATTLEFIELD_HEIGHT || w >= BATTLEFIELD_WIDTH)
		return nullptr;
	return map_[h][w];
}

void Map::drawMap()
{
	"Drawing map\n";
	for (int i = 0; i < BATTLEFIELD_HEIGHT; i++)
	{
		for (int j = 0; j < BATTLEFIELD_WIDTH; j++)
		{
			std::cout << this->getCreatureByCoordinates(i,j)->getAssociatedTag();
		}
		std::cout << "\n";
	}
	for (int i = 0; i < BATTLEFIELD_HEIGHT; i++)
	{
		for (int j = 0; j < BATTLEFIELD_WIDTH; j++)
		{
			std::cout << this->getCreatureByCoordinates(i, j)->getPosition();
		}
		std::cout << "\n";
	}
	std::cout << "Map is drawn\n";
}