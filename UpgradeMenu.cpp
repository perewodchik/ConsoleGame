#include <UpgradeMenu.h>

UpgradeMenu::UpgradeMenu(std::vector< std::unique_ptr<Player> >& players,
	TargetController* targetController) :m_players(players)
{
	m_targetController = targetController;
}

void UpgradeMenu::run()
{

}