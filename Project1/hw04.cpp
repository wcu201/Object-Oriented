#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Warrior
{
	string name;
	double strength;
	bool employed = false;//tells whether the warrior is employed
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

	void changeEmployment()//changes warrior to the opposited of what they are (employed of unemployed)
	{
		employed = !employed;
	}

	bool getEmployment()//returns whether the warrior is employed or not
	{
		return employed;
	}

	void display()//displays warrior name and strength
	{
		cout << name << ": " << strength << endl;
	}
};
//Warrior Class

class Noble
{
	vector<Warrior*> Army;//vector of Warrior pointers
	string name;
public:
	Noble(string name = "Noble") : name(name) {};
	//Noble Constructor
	string getName()
	{
		return name;
	}
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

		cout << "You don't work for me anymore " << Army[index]->getName() << "! -- " << name << endl;

		for (size_t p = index; p < Army.size() - 1; p++)
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
	//Allows Nobles to battle each other

};
//Noble Class

void Status(vector<Noble*> &allNobles, vector<Warrior*> &allWarriors)
{
	cout << "Status" << endl << "======" << endl << "Nobles:" << endl;
	if (allNobles.size() == 0)
		cout << "NONE" << endl;
	else
	for (size_t i = 0; i < allNobles.size(); i++)
	{
		allNobles[i]->display();
	}

	bool unemployed = false;
	for (size_t i = 0; i < allWarriors.size(); i++)
	{
		if (allWarriors[i]->getEmployment() == false)
			unemployed = true;
	}
	cout << "Unemployed Warriors: " <<  endl;
	if (unemployed == false)
		cout << "NONE" << endl;
	else
	for (size_t i = 0; i < allWarriors.size(); i++)
	{
		if (allWarriors[i]->getEmployment() == false)
			allWarriors[i]->display();
	}

}
//Prints Status

void Clear(vector<Noble*> &allNobles, vector<Warrior*> &allWarriors)
{
	for (size_t i = 0; i < allNobles.size(); i++)
	{
		delete allNobles[i];
	}

	for (size_t p = 0; p < allWarriors.size(); p++)
	{
		delete allWarriors[p];
	}

	allNobles.clear();
	allWarriors.clear();
}
//Clears All

int main()
{
	vector<Noble*> allNobles;
	//vector of Nobles

	vector<Warrior*> allWarriors;
	//vector of Warriors

	string commandType;
	string command;
	int strength;
	string employee;
	string opponent1;
	string opponent2;
	cout << "Enter file name" << endl;
	string filename;
	cin >> filename;
	fstream file(filename);
	if (!file)//Prints Error is file does not exist 
	{
		cerr << "Unable to open file." << endl;
	}

	while (file >> commandType)
	{
		if (commandType == "Noble")
		{
			file >> command;
			bool alreadyExists = false;
			for (size_t i = 0; i < allNobles.size(); i++)
			{
				if (allNobles[i]->getName() == command)
					alreadyExists = true;
			}

			if (alreadyExists == true)//If the Noble already exists print error
				cerr << "Error! Noble " << command << " already exists." << endl;
			else
			{
				Noble* newNoble = new Noble(command);
				allNobles.push_back(newNoble);//Creates Noble and adds pointer variable to vector
			}
		}
		//Noble Command

		if (commandType == "Warrior")
		{
			file >> command >> strength;
			bool alreadyExists = false;
			for (size_t i = 0; i < allWarriors.size(); i++)
			{
				if (allWarriors[i]->getName() == command)
					alreadyExists = true;
			}

			if (alreadyExists == true)
				cerr << "Error! Warrior " << command << " already exists." << endl;//If the warrior already exists print an error message
			else
			{
				Warrior* newWarrior = new Warrior(command, strength);
				allWarriors.push_back(newWarrior);//creates a new warrior and adds a pointer variable to the vector
			}
		}
        //Warrior Command

		if (commandType == "Hire")
		{

			file >> command >> employee;
			bool nobleExists = false;
			bool warriorExists = false;
			for (size_t i = 0; i < allNobles.size(); i++)
			{
				if (allNobles[i]->getName() == command)
					nobleExists = true;//sets true if the Noble exists
			}

			for (size_t i = 0; i < allWarriors.size(); i++)
			{
				if (allWarriors[i]->getName() == employee)
					warriorExists = true;//sets true if the warrior exists
			}

			if (nobleExists == false || warriorExists == false)
			{
				if(nobleExists == false)
					cerr << "Error! Noble " << command << " does not exist." << endl;//error message if noble doesn't exist
				if (warriorExists == false)
					cerr << "Error! Warrior " << employee << " does not exist." << endl;//error message if warrior doesn't exist
			}
			else
			{
				int noble = 0;
				int warrior = 0;
				for (size_t i = 0; i < allNobles.size(); i++)
				{
					if (allNobles[i]->getName() == command)
						noble = i;//finds noble in vector
				}

				for (size_t i = 0; i < allWarriors.size(); i++)
				{
					if (allWarriors[i]->getName() == employee)
						warrior = i;//finds warrior in vector
				}

				allWarriors[warrior]->changeEmployment();//sets warrior to employed

				allNobles[noble]->hire(*allWarriors[warrior]);//adds pointer to warrior in vector for Noble's army
			}

		}
		//Hire Command

		if (commandType == "Fire")
		{
			file >> command >> employee;
			bool nobleExists = false;
			bool warriorExists = false;
			for (size_t i = 0; i < allNobles.size(); i++)
			{
				if (allNobles[i]->getName() == command)
					nobleExists = true;//sets true if the Noble exists
			}

			for (size_t i = 0; i < allWarriors.size(); i++)
			{
				if (allWarriors[i]->getName() == employee)
					warriorExists = true;//sets true if the warrior exists
			}

			if (nobleExists == false || warriorExists == false)
			{
				if (nobleExists == false)
					cerr << "Error! Noble " << command << " does not exist." << endl;//error message if noble doesn't exist
				if (warriorExists == false)
					cerr << "Error! Warrior " << employee << " does not exist." << endl;//error message if warrior doesn't exist
			}
			else
			{
				int noble = 0;
				int warrior = 0;
				for (size_t i = 0; i < allNobles.size(); i++)
				{
					if (allNobles[i]->getName() == command)
						noble = i;//finds noble in vector
				}

				for (size_t i = 0; i < allWarriors.size(); i++)
				{
					if (allWarriors[i]->getName() == employee)
						warrior = i;//finds warrior in vector
				}

				allWarriors[warrior]->changeEmployment();//sets warrior to iunemployed

				allNobles[noble]->fire(*allWarriors[warrior]);//removes pointer to warrior in vector for Noble's army
			}
		}
		//Fire Command

		if (commandType == "Battle")
		{
			file >> opponent1 >> opponent2;
			bool nobleExists = false;
			bool noble2Exists = false;
			for (size_t i = 0; i < allNobles.size(); i++)
			{
				if (allNobles[i]->getName() == opponent1)
					nobleExists = true;//sets true if Noble exists
			}

			for (size_t i = 0; i < allNobles.size(); i++)
			{
				if (allNobles[i]->getName() == opponent2)
					noble2Exists = true;//sets true if Noble's opponent exists
			}

			if (nobleExists == false || noble2Exists == false)
			{
				if (nobleExists == false)//prints error message if noble doesn't exiist
					cerr << "Error! The Noble " << opponent1 << " does not exist. No battle occured." << endl;
				if (noble2Exists == false)//prints error message if noble's opponent doesn't exist
					cerr << "Error! The Noble " << opponent2 << " does not exist. No battle occured." << endl;
			}
			else
			{
				int noble = 0;
				int noble2 = 0;
				for (size_t i = 0; i < allNobles.size(); i++)
				{
					if (allNobles[i]->getName() == opponent1)
						noble = i;//finds noble in vector
				}

				for (size_t i = 0; i < allNobles.size(); i++)
				{
					if (allNobles[i]->getName() == opponent2)
						noble2 = i;//find's nobles opponent in vector
				}

				allNobles[noble]->battle(*allNobles[noble2]);//Battle method called
			}
			
			
		}
		//Battle Command

		if (commandType == "Status")
		{
			Status(allNobles, allWarriors);
			//Calls Status command
		}
		//Status Command

		if (commandType == "Clear")
		{
			Clear(allNobles, allWarriors);
			//Callse clear command
		}
		//Clear Command
	}

	cin.get();
	cin.get();
}