#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>

namespace WarriorCraft {
	class Noble;

	class Warrior
	{
	public:
		Warrior(const std::string& name, int strength);

		double getStrength();
		void setStrength(double newStrength);
		std::string getName();
		void giveLeader(Noble& myLeader);
		void runaway();


	private:
		std::string name;
		int strength;
		Noble* leader = nullptr;
	};
}

#endif

