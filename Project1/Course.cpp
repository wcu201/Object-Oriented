#include <iostream>
#include "Course.h"
#include "Student.h"

using namespace std;
namespace BrooklynPoly
{

	Course::Course(const string& name) : name(name) {}

	void Course::addStudent(std::string name, std::vector<Student>& allStudents)
	{
		for (size_t i = 0; i < allStudents.size(); i++)		{			if (name == allStudents[i].getName())				theStudents.push_back(&allStudents[i]);		}
	}
}