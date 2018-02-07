#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct Warrior//Warrior object
{
	string name;
	int strength;
};


void CreateWarrior(string n, int s, vector<Warrior>& AllWarriors)//Warrior Command function
{ 
	Warrior newWarrior;
	newWarrior.name = n;
	newWarrior.strength = s;
	AllWarriors.push_back(newWarrior);//puts warrior into vector of warriors
}

void Battle(string opp1, string opp2, vector<Warrior>& AllWarriors)//Battle Command function
{
	int fighter1 = 0;//int value that will hold the index of where the first warrior is
	int fighter2 = 0;//int value that will hold the index of where the second warrior is
	for (size_t o = 0; o < AllWarriors.size(); o++)
	{
		if (AllWarriors[o].name == opp1)
			fighter1 = o;
		if (AllWarriors[o].name == opp2)
			fighter2 = o;
	}
	string fightTitle = AllWarriors[fighter1].name + " battles " + AllWarriors[fighter2].name;//Creates title of a battle
	if (AllWarriors[fighter1].strength == 0 || AllWarriors[fighter2].strength == 0)//Checks if any of the warriors was dead prior to battle
	{
		if (AllWarriors[fighter1].strength == 0 && AllWarriors[fighter2].strength == 0)
			cout << fightTitle << endl << "Oh, NO! They're both dead! Yuck!" << endl;
		else
			if (AllWarriors[fighter2].strength == 0)
				cout << fightTitle << endl << "He's dead, " << AllWarriors[fighter1].name << endl;
			else
				cout << fightTitle << endl << "Your dead, " << AllWarriors[fighter1].name << endl;
	}
	else
	{ 
		int strength1 = AllWarriors[fighter1].strength;
		int strength2 = AllWarriors[fighter2].strength;
		AllWarriors[fighter1].strength = strength1 - strength2;
		AllWarriors[fighter2].strength = strength2 - strength1;
		//Adjusts strengths after fight. Winners will be positive. Losers will be negative
		if (AllWarriors[fighter1].strength == 0)//Checks if both warriors had equal strength
			cout << fightTitle << endl << "Mutual Annihilation: " << AllWarriors[fighter1].name << " and " << AllWarriors[fighter2].name << " die at each other's hands" << endl;
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

void Status(vector<Warrior>& AllWarriors)//Status Command function
{
	int count = 0;

	for (size_t c = 0; c < AllWarriors.size(); c++)
	{
		count++;//Counts how many warriors there are
	}
	cout << "Number of Warriors: " << count << endl;
	for (size_t a = 0; a < AllWarriors.size(); a++)
	{
		cout << "Warrior: " << AllWarriors[a].name << ", strength: " << AllWarriors[a].strength << endl;//prints warrior strength and name
	}
}

int main()
{
	vector<Warrior> AllWarriors;
	string commandType;
	string command;
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
			file >> command >> strength;
			CreateWarrior(command, strength, AllWarriors);//Calls CreateWarrior command
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