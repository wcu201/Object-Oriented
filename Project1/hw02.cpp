#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Weapon
{
	int strength = 0;//Weapon's Strength
	string name;//Weapon's Name
public:
	Weapon(int strength = 0, string name = "weapon"): strength(strength), name(name) {};//Weapon constructor
	void setStrength(int weaponStrength)//Changes weapon strength
	{
		strength = weaponStrength;
	}

	int getStrength()//return's weapon strength
	{
		return strength;
	}
	string getName()//return's weapon name
	{
		return name;
	}

};



class Warrior
{
private:
	Weapon myWeapon;
	string name;
	int strength = myWeapon.getStrength(); //(never used)precautionary
public:
	Warrior(Weapon myWeapon, string name): myWeapon(myWeapon), name(name) {};//Warrior Constructor
	string getWepName()//return's warrior's weaon's name
	{
		return myWeapon.getName();
	}
	string getName()//return's warrior's name
	{
		return name;
	}
	int getWepStrength()//returns warrior's weapon's strength
	{
		return myWeapon.getStrength();
	}


	void setWepStrength(int newStrength)//Weapon strength setter
	{
		myWeapon.setStrength(newStrength);
	}

	int findOpponent(string opponent, vector<Warrior>& AllWarriors)//Method that will find the index of the warrior's opponent in the vector according to name
	{
		int foe = 0;
		for (int i = 0; i < AllWarriors.size(); i++)
		{
			if (opponent == AllWarriors[i].getName())
				foe = i;
		}

		return foe;
	}

	void battle(string opponent, vector<Warrior> &AllWarriors)//Battle method
	{
		int foe = findOpponent(opponent, AllWarriors);

		string fightTitle = name + " battles " + AllWarriors[foe].getName();//Creates title of a battle
		if (myWeapon.getStrength() == 0 || AllWarriors[foe].myWeapon.getStrength() == 0)//Checks if any of the warriors was dead prior to battle
			cout << fightTitle << endl << "No battle occured. At least one of the warriors is already dead" << endl;
		else
		{
			int strength1 = myWeapon.getStrength();
			int strength2 = AllWarriors[foe].myWeapon.getStrength();
			setWepStrength(strength1 - strength2);
			AllWarriors[foe].setWepStrength(strength2 - strength1);
			//Adjusts strengths after fight. Winners will be positive. Losers will be negative
			if (myWeapon.getStrength() == 0)//Checks if both warriors had equal strength
				cout << fightTitle << endl << "Both " << name << " and " << AllWarriors[foe].name << " die." << endl;
			else if (myWeapon.getStrength() > 0)
			{
				AllWarriors[foe].setWepStrength(0);
				cout << fightTitle << endl << name << " defeats " << AllWarriors[foe].name << endl;
			}
			else
			{
				AllWarriors[foe].setWepStrength(0);
				cout << fightTitle << endl << AllWarriors[foe].name << " defeats " << name << endl;
			}
			//adjusts loser strength to 0 and declares winner
		}

	}

	
};

void Status(vector<Warrior>& AllWarriors)//Status Command function
{
	int count = 0;

	for (int c = 0; c < AllWarriors.size(); c++)
	{
		count++;//Counts how many warriors there are
	}
	cout << "Number of Warriors: " << count << endl;
	for (int a = 0; a < AllWarriors.size(); a++)
	{
		cout << "Warrior: " << AllWarriors[a].getName() << ", weapon: " << AllWarriors[a].getWepName() << ", " << AllWarriors[a].getWepStrength() << endl;
		//prints warrior weapon strength and name of warrior and weapon
	}
}

int findWarrior(string warrior,vector<Warrior>& AllWarriors)//method called in battle command to find the warrior in vector that is starting the battle
{
	int fighter = 0;
	for (int i = 0; i < AllWarriors.size(); i++)
	{
		if (warrior == AllWarriors[i].getName())
		{
			fighter = i;
		}
	}
	return fighter;
}

int main()
{
	vector<Warrior> AllWarriors;

	
	string commandType;
	string command;
	string weaponName;
	int strength;
	string opponent1;
	string opponent2;
	cout << "Enter file name" << endl;
	string filename;
	cin >> filename;
	fstream file(filename);
	if (!file)
	{
		cerr << "Unable to open file." << endl;
	}

	while (file >> commandType)
	{
		if (commandType == "Warrior")
		{
			file >> command >> weaponName >> strength;
			Weapon weaponName(strength, weaponName);
			Warrior newWarrior(weaponName, command);
			newWarrior.setWepStrength(strength);
			AllWarriors.push_back(newWarrior);
			//Creates Weapon and Warrior holding it then puts the warrior in the vector
		}
		if (commandType == "Battle")
		{
			file >> opponent1 >> opponent2;
			AllWarriors[findWarrior(opponent1, AllWarriors)].battle(opponent2, AllWarriors);
			//Battle method called
		}
		if (commandType == "Status")
		{
			Status(AllWarriors);//Calls Status command
		}

	}


	
	cin.get();
	cin.get();

}