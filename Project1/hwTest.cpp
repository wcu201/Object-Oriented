#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Protector
{
protected:
	int strength;
	string name;
public:
	Protector (string name, int strength): name(name), strength(strength){}
	virtual int getStrength() = 0;
};

class Warrior: public Protector
{

public:
	Warrior(string name, int strength = 0): Protector(name, strength) {}
	virtual int getStrength() = 0;
};

class Archer: public Warrior
{
public:
	Archer(string name, int strength = 0): Warrior(name, strength) {}
	int getStrength()
	{
		return strength;
	}
};

class Noble
{
protected:
	string name;
public:
	Noble (string name): name(name) {}

	string getName()
	{
		return name;
	}

	virtual int getStrength() = 0;
};

class Lord: public Noble
{
private:
	vector <Protector*> Army;
	
public:
	Lord (string name): Noble(name) {}



	int getStrength()
	{
		int total = 0;

		for (size_t i = 0; i < Army.size(); i++)
		{
			total += Army[i]->getStrength();
		}

		return total;
	}

	void hires(Protector& theProtector)
	{
		Protector* newProtector = &theProtector;
		Army.push_back(newProtector);
	}



	void battle(Noble &opp)
	{
		cout << name << " battles " << opp.getName() << endl;

		if (opp.getStrength() == 0 || getStrength() == 0)
		{
			if (opp.getStrength() == 0 && getStrength() == 0)
				cout << "Oh, NO!They're both dead!  Yuck!" << endl;
			else
			{
				if (opp.getStrength() == 0)
					cout << "He's dead, " << opp.getName() << endl;
				if (getStrength() == 0)
					cout << "He's dead, " << name << endl;
			}
		}

		else
		{
			if (getStrength() > opp.getStrength())
				cout << getStrength() << " " << name;
			else
				cout << opp.getName();
		}
		

	}
};

class PersonWithStrengthToFight: public Noble
{
	int strength;
public:
	PersonWithStrengthToFight (string name, int strength): Noble(name), strength(strength) {}

	int getStrength()
	{
		return strength;
	}
};

int main()
{
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	cin.get();
}