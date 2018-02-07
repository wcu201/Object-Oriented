#ifndef NOBLE_H
#define NOBLE_H

#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft {

	class Warrior;

	class Noble
	{
	public:
		Noble(const std::string& name);
		void display(std::ostream& os) const;
		void hire(Warrior& theWarrior);
		void battle(Noble& opp);
		double getArmyStrength();
		void removeWarrior(Warrior& oldWarrior);
		std::string getName();

	private:
		std::string name;
		std::vector<Warrior*> Army;
	};

}

#endif#pragma once
