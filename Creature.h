#pragma once
#include <vector>
#include <Position.h>
#include <memory>
#include <IUser.h>
#include <Skill.h>
class Creature : public IUser
{
public:
	Creature(int health, int armor, int initiative, 
		int maxExp, int killExp, std::string name, char tag);
	~Creature() = default;

	//IUser inherited methods
	int      getTeam() { return m_team; };
	Position getPosition() { return m_position; };

	//Creature getter methods
	int  getHealth     () const { return m_health;      };
	int  getMaxHealth  () const { return m_maxHealth;   };
	int  getArmor      () const { return m_armor;       };
	int  getExp        () const { return m_curExp;      };
	int  getKillExp    () const { return m_killExp;     };
	int  getInitiative () const { return m_initiative;  };
	bool getIsDefending() const { return m_isDefending; };
	char getTag        () const { return m_tag;         };
	std::string getName() const { return m_name;        };

	std::vector<std::shared_ptr<Skill> > getSkills() { return m_skills; };

	//Creature setter methods
	void setTeam(int team);
	void setPosition(Position pos);

	//Battle related methods
	void takeDamage   (int value);
	void receiveHeal  (int value);
	void addExperience(int value);
	void startDefending();
	void castSkill(int index);

private:
	bool m_isDefending;
	int  m_health;
	int  m_maxHealth;
	int  m_armor;
	int  m_initiative;
	int  m_curExp;
	int  m_maxExp;
	int  m_killExp;
	int  m_team;
	char m_tag;
	std::string m_name;
	Position m_position;
protected:
	std::vector<std::shared_ptr<Skill> > m_skills;
};

