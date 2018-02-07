
#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <vector>

namespace BrooklynPoly {


	class Course;

	class Student
	{
	private:
		std::string name;
		std::vector<Course*> myCourses;

	public:
		Student(const std::string& name);

		std::string getName()
		{
			return name;
		}

		void addCourse(std::string name, std::vector<Course>& allCourses);
		

	};

}

#endif

