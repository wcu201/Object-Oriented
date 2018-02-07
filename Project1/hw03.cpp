#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Warrior
{
	string name;
	double strength;
public:
	Warrior(string name = "warrior", int strength = 0) : name(name), strength(strength) {};
	//Warrior Constructor
	string getName()
	{
		return name;
	}
	double getStrength()
	{
		return strength;
	}
	void setStrength(double newStrength)
	{
		strength = newStrength;
	}
};

class Noble
{
	vector<Warrior*> Army;//vector of Warrior pointers
	string name;
public:
	Noble(string name = "Noble") : name(name) {};
	//Noble Constructor
	void hire(Warrior& theWarrior)
	{
		Warrior* newWarrior = &theWarrior;
		Army.push_back(newWarrior);
	}
	//Hires Warriors
	void fire(Warrior& theWarrior)
	{
		int index = 0;
		for (size_t i = 0; i < Army.size(); i++)
		{
			if (Army[i]->getName() == theWarrior.getName())
				index = i;
		}

		for (size_t p = index; p < Army.size()-1; p++)
		{
			Army[p] = Army[p + 1];
		}

		Army.pop_back();
		
	}
	//Fires Warriors
	double getArmyStrength()
	{
		double strength = 0;

		for (size_t i = 0; i < Army.size(); i++)
		{
			strength += Army[i]->getStrength();
		}

		return strength;
	}
	//returns total army strength
	void display()const
	{
		cout << name << " has an army of " << Army.size() << endl;
		for (size_t i = 0; i < Army.size(); i++)
		{
			cout << "          " << Army[i]->getName() << ": " << Army[i]->getStrength() << endl;
		}

	}
	//Displays army size all warriors and their strength
	void battle(Noble& opp)
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
					cout << " ________________" << endl << "| They're Both   |" << endl << "|    Already     |" << endl;
					cout << "|      Dead      |" << endl << "|________________|" << endl << "(\\_/)  |" << endl;
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
	//Allows Nobles to battle each other

};

int main()
{
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
	cin.get();
}