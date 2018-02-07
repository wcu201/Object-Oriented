#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;
using namespace BrooklynPoly;




int main()
{
	vector<Course> allCourses;
	Course newCourse("class");
	allCourses.push_back(newCourse);
	Student bob("bob");
	cout << bob.getName();
	bob.addCourse("class", allCourses);
	cin.get();
	return 0;
}