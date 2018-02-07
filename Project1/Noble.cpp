#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace WarriorCraft {

	Noble::Noble(const string& name) : name(name) {}

	void Noble::display(ostream& os) const
	{
		cout << name << " has an army of " << Army.size() << endl;
		for (size_t i = 0; i < Army.size(); i++)
		{
			cout << "          " << Army[i]->getName() << ": " << Army[i]->getStrength() << endl;
		}

	}

	void Noble::hire(Warrior& theWarrior)
	{
		theWarrior.giveLeader(*this);
		Warrior* newWarrior = &theWarrior;
		Army.push_back(newWarrior);
	}

	void Noble::battle(Noble& opp)
	{
		cout << name << " battles " << opp.name << endl;

		if (getArmyStrength() == 0 || opp.getArmyStrength() == 0)
		{
			if (opp.getArmyStrength() != 0)
			{
				cout << "You're dead " << name << endl;
			}
			else
			{
				if (getArmyStrength() != 0)
					cout << "He's dead " << name << endl;
				else
				{
					cout << " _____________" << endl << "| You Both   |" << endl << "|  Already   |" << endl;
					cout << "|    Dead    |" << endl << "|____________|" << endl << "(\\_/)  |" << endl;
					cout << "(> <)  |" << endl << "/ ~|   ()" << endl;
				}
			}
		}
		else
		{

			if (getArmyStrength() > opp.getArmyStrength())
			{
				for (size_t p = 0; p < Army.size(); p++)
				{
					Army[p]->setStrength(Army[p]->getStrength() - opp.getArmyStrength() / (3 * Army.size()));
				}
				for (size_t i = 0; i < opp.Army.size(); i++)
				{
					opp.Army[i]->setStrength(0);
				}
				cout << name << " defeats " << opp.name << endl;
			}

			if (getArmyStrength() < opp.getArmyStrength())
			{
				for (size_t p = 0; p < Army.size(); p++)
				{
					opp.Army[p]->setStrength(opp.Army[p]->getStrength() - getArmyStrength() / (3 * opp.Army.size()));
				}
				for (size_t i = 0; i < Army.size(); i++)
				{
					Army[i]->setStrength(0);
				}
				cout << opp.name << " defeats " << name << endl;
			}

			if (getArmyStrength() == opp.getArmyStrength())
			{
				for (size_t i = 0; i < opp.Army.size(); i++)
				{
					opp.Army[i]->setStrength(0);
				}
				for (size_t i = 0; i < Army.size(); i++)
				{
					Army[i]->setStrength(0);
				}
				cout << "Mutual Annihalation: " << name << " and " << opp.name << " die at each other's hands" << endl;
			}
		}


	}

	double Noble::getArmyStrength()
	{
		double strength = 0;

		for (size_t i = 0; i < Army.size(); i++)
		{
			strength += Army[i]->getStrength();
		}

		return strength;
	}

	void Noble::removeWarrior(Warrior& oldWarrior)
	{
		for (size_t i = 0; i < Army.size(); i++)
		{
			if (Army[i] == &oldWarrior)
			{
				for (size_t p = i; p < Army.size() - 1; p++)
				{
					Army[p] = Army[p + 1];
				}
				Army.pop_back();
			}
		}
	}

	string Noble::getName()
	{
		return name;
	}
}
