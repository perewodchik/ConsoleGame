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
		for (auto creature : players_[i]->getHeroes())
		{
			if (current_row >= BATTLEFIELD_WIDTH) 
			{
				current_row = 0;
				current_column++;
			}
			if (current_column >= BATTLEFIELD_HEIGHT)
			{
				std::cout << "There's not enough space on the battlefield\n";
				throw "Not enough space";
			}

			map_[current_column][current_row] = creature;
			current_row++;
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
	std::cout << "Map is drawn\n";
}