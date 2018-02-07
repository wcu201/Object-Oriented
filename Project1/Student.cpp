#include <iostream>
#include "Student.h"#include "Course.h"using namespace std;namespace BrooklynPoly{	Student::Student(const string& name) : name(name) {}	void Student::addCourse(std::string name, std::vector<Course>& allCourses)
	{		for (size_t i = 0; i < allCourses.size(); i++)		{			if (name == allCourses[i].getName())				myCourses.push_back(&allCourses[i]);		}	}}