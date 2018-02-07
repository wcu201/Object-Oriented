#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Protector
{
protected:
	string name;
	int strength;
	bool warrior;//Used later to specify what the protector says in battle
	bool alive = true;//If the protector is alive or not
public:
	Protector(string name = "", int strength = 0, bool warrior = true) : name(name), strength(strength), warrior(warrior) {}

	void display()
	{
		cout << name << ": " << strength << endl;
	}

	string getName()
	{
		return name;
	}

	bool getMortality()
	{
		return alive;
	}

	void die()
	{
		alive = false;
	}

	void setStrength(int newStrength)
	{
		strength = newStrength;
	}

	virtual int getStrength() = 0;

	virtual bool getType() = 0;

	virtual void fight() = 0;
};

class Warrior : public Protector
{
public:
	Warrior(string name = "", int strength = 0, bool warrior = true) : Protector(name, strength) {}

	virtual void fight() = 0;

	virtual int getStrength() = 0;

	bool getType()
	{
		return warrior;
	}

};

class Wizard : public Protector
{
protected:
	bool warrior;
public:
	Wizard(string name = "", int strength = 0, bool warrior = false) : Protector(name, strength), warrior(warrior) {}
	int getStrength()
	{
		return strength;
	}

	void fight()
	{
		cout << "POOF" << endl;
	}

	bool getType()
	{
		return warrior;
	}
};

class Archer : public Warrior
{
public:
	Archer(string name = "", int strength = 0) : Warrior(name, strength) {}

	void fight()
	{
		cout << "TWANG! " << name << " says: Take that in the name of my lord, ";
	}

	int getStrength()
	{
		return strength;
	}
};

class Swordsman : public Warrior
{
public:
	Swordsman(string name = "", int strength = 0) : Warrior(name, strength) {}

	void fight()
	{
		cout << "CLANG! " << name << " says: Take that in the name of my lord, ";
	}

	int getStrength()
	{
		return strength;
	}
};

class Noble
{
protected:
	string name;
	bool alone;
	int strength;
	bool alive = true;
public:
	Noble(string name = " ", bool alone = false) : name(name), alone(alone) {}
	string getName()
	{
		return name;
	}

	bool getAlone()
	{
		return alone;
	}

	bool getMortality()
	{
		return alive;
	}

	virtual void die() = 0;

	virtual int getStrength() = 0;

	virtual void setStrength(int newStrength) = 0;

	virtual void battle(Noble &opp) = 0;
    

};

class PersonWithStrengthToFight : public Noble
{

	int strength;

public:
	PersonWithStrengthToFight(string name = "", int strength = 0, bool alone = true) : Noble(name, alone), strength(strength){}

	int getStrength()
	{
		return PersonWithStrengthToFight::strength;
	}

	void setStrength(int newStrength)
	{
		strength = newStrength;
	}

	void display()
	{
		cout << name << " " << strength;
	}

	void die()
	{
		alive = false;
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
			if (opp.getStrength() > getStrength())
			{
				cout << opp.getName() << " defeats " << name << endl;
				if (opp.getAlone() == true)
				{
					opp.setStrength(opp.getStrength() - getStrength());
				}
				else
				{
				}
			}
			else
			{
				if (opp.getStrength() < getStrength())
					cout << name << " defeats " << opp.getName() << endl;
				else
					cout << "Mutual Annihalation " << endl;
			}

		}
	}
};

class Lord : public Noble
{
	vector <Protector*> Army;


public:
	Lord(string name = " ", bool alone = false ) : Noble(name, alone) {}

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

	void fires(Protector& theProtector)
	{
		int index = 0;
		for (size_t i = 0; i < Army.size(); i++)
		{
			if (Army[i]->getName() == theProtector.getName())
				index = i;
		}

		for (size_t i = index; i < Army.size() - 1; i++)
		{
			Army[i] = Army[i + 1];
		}

		Army.pop_back();
	}

	void die()
	{
		for (size_t i = 0; i < Army.size(); i++)
		{
			Army[i]->die();
		}

		alive = false;
	}

	void setStrength(int newStrength)
	{
		cout << endl;
	}
	void display()
	{
		cout << name << ":" << endl;
		for (size_t i = 0; i < Army.size(); i++)
		{
			Army[i]->display();
		}
	}

	void battle(Noble &opp)
	{
		cout << name << " battles " << opp.getName() << endl;

		if (opp.getMortality() == false || getMortality() == false)
		{
			if (opp.getMortality() == false && getMortality() == false)
				cout << "Oh, NO!They're both dead!  Yuck!" << endl;
			else
			{
				if (opp.getMortality() == true)
					cout << "He's dead, " << opp.getName() << endl;
				if (getMortality() == true)
					cout << "He's dead, " << name << endl;
			}
		}
		else
		{
			for (size_t i = 0; i < Army.size(); i++)
			{
				if (Army[i]->getType() == true)
				{
					Army[i]->fight();
					cout << name << endl;
				}
				else
					Army[i]->fight();
			}
			if (opp.getStrength() > getStrength())
			{
				cout << opp.getName() << " defeats " << name << endl;
				die();
			}

			else
			{
				if (opp.getStrength() < getStrength())
				{
					cout << name << " defeats " << opp.getName() << endl;
					opp.die();
				}
				else
				{
					cout << "Mutual Annihalation " << endl;
					die();
					opp.die();
				}
			}
		}
		
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
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);

	cin.get();
}
