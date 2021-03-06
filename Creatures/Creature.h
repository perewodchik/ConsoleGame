#pragma once
#include <vector>
#include <Misc/Position.h>
#include <memory>
#include <Misc/IUser.h>
#include <Skills/Skill.h>
class Creature : public IUser
{
public:
	Creature(int health, int armor, int initiative, 
		int maxExp, int killExp, std::string name);
	~Creature() = default;

	enum class CLASS {
		Apprentice, Assassin, Peasant,
		Archer, Knight, Priest, Shinobi, Spirit, Warlock,
		Anduin, Naruto, Hanzo, Paladin
	};
	
	//IUser inherited methods
	int      getTeam() { return m_team; };
	Position getPosition() { return m_position; };

	//Creature getter methods
	int  getHealth     () const { return m_health;       };
	int  getMaxHealth  () const { return m_maxHealth;    };
	int  getArmor      () const { return m_armor;        };
	int  getMaxExp     () const { return m_maxExp;       };
	int  getKillExp    () const { return m_killExp;      };
	int  getInitiative () const { return m_initiative;   };
	bool getIsDefending() const { return m_isDefending;  };
	char getTag        () const { return m_tag;          };
	std::string getName() const { return m_name;         };
	int  isDead        () const { return m_isDead;		 };
	int  getEvasion    () const { return m_evasion;      };

	std::vector<CLASS>  getUpgrades() const { return m_upgrades;};

	std::vector<std::shared_ptr<Skill> > getSkills() { return m_skills; };

	//Creature setter methods
	void setTeam(int team)		   { m_team = team;    };
	void setPosition(Position pos) { m_position = pos; };
	void setIsDead(bool state)     { m_isDead = state; };

	//Battle related methods
	int takeDamage   (int value);
	int receiveHeal  (int value);
	int receiveArmor (int value);
	void startDefending();
	void stopDefending();

	

private:
	bool m_isDefending;
	int  m_health;
	int  m_maxHealth;
	int  m_armor;
	int  m_initiative;
	int  m_maxExp;
	int  m_killExp;
	int  m_team;
	char m_tag;
	int m_isDead;
	
	std::string m_name;
	Position m_position;
protected:
	int m_evasion;
	std::vector<CLASS> m_upgrades;
	std::vector<std::shared_ptr<Skill> > m_skills;
};

