#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct Weapon
{
	string name;
	int strength;
};

int findOpp(const string& opp, const vector<Warrior>& AllWarriors);
class Warrior//Warrior object
{
	Weapon weapon_choice;
	string name;
	//int strength;
public:
	int get_strength();
	string get_weaponName();
	string get_name() const;
	void Battle(string opp2, vector<Warrior>& AllWarriors)//Battle Command function
	{
		//int value that will hold the index of where the first warrior is
		int fighter2 = 0;//int value that will hold the index of where the second warrior is

		string fightTitle = opp2 + " battles " + opp2;//Creates title of a battle
		if (AllWarriors[fighter1].strength == 0 || AllWarriors[fighter2].strength == 0)//Checks if any of the warriors was dead prior to battle
			cout << fightTitle << endl << "No battle occured. At least one of the warriors is already dead" << endl;
		else
		{
			int strength1 = AllWarriors[fighter1].strength;
			int strength2 = AllWarriors[fighter2].strength;
			AllWarriors[fighter1].strength = strength1 - strength2;
			AllWarriors[fighter2].strength = strength2 - strength1;
			//Adjusts strengths after fight. Winners will be positive. Losers will be negative
			if (AllWarriors[fighter1].strength == 0)//Checks if both warriors had equal strength
				cout << fightTitle << endl << "Both " << AllWarriors[fighter1].name << " and " << AllWarriors[fighter2].name << " die." << endl;
			else if (AllWarriors[fighter1].strength > 0)
			{
				AllWarriors[fighter2].strength = 0;
				cout << fightTitle << endl << AllWarriors[fighter1].name << " defeats " << AllWarriors[fighter2].name << endl;
			}
			else
			{
				AllWarriors[fighter1].strength = 0;
				cout << fightTitle << endl << AllWarriors[fighter2].name << " defeats " << AllWarriors[fighter1].name << endl;
			}
			//adjusts loser strength to 0 and declares winner
		}
	}

	 
};
int findOpp(const string& opp, const vector<Warrior>& AllWarriors)
{

	for (int fighterPositon = 0; fighterPositon < AllWarriors.size(); fighterPositon++)
	{
		if (AllWarriors[fighterPositon].get_name() == opp)
			return fighterPositon;

	}
}


void CreateWarrior(string n, int s, string theWeapon, vector<Warrior>& AllWarriors)//Warrior Command function
{
	Warrior newWarrior;
	newWarrior.name = n;
	newWarrior.strength = s;
	newWarrior.set_weapon(theWeapon, s);
	AllWarriors.push_back(newWarrior);//puts warrior into vector of warriors
}



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
		cout << "Warrior: " << AllWarriors[a].name << ", strength: " << AllWarriors[a].strength << endl;//prints warrior strength and name
	}
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
			CreateWarrior(command, strength, weaponName, AllWarriors);//Calls CreateWarrior command
		}
		if (commandType == "Battle")
		{
			file >> opponent1 >> opponent2;
			Battle(opponent1, opponent2, AllWarriors);//Calls Battle command
		}
		if (commandType == "Status")
		{
			Status(AllWarriors);//Calls Status command
		}

	}


	cin.get();
	cin.get();
	return 0;
}