#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace WarriorCraft {

	Warrior::Warrior(const std::string& name, int strength) : name(name), strength(strength) {}

	double Warrior::getStrength()
	{
		return strength;
	}

	void Warrior::setStrength(double newStrength)
	{
		strength = newStrength;
	}

	string Warrior::getName()
	{
		return name;
	}

	void Warrior::giveLeader(Noble& myLeader)
	{
		Noble* theLeader = &myLeader;
		leader = theLeader;
	}

	void Warrior::runaway()
	{
		cout << name << " flees in terror, abandoning his lord, " << leader->getName() << endl;
		leader->removeWarrior(*this);
		leader = nullptr;
	}
}