#include <string>
#include <vector>
#ifndef COURSE_H
#define COURSE_H

namespace BrooklynPoly {

	class Student;

	class Course
	{
	private:
		std::string name;
		std::vector<Student*> theStudents;
	public:
		Course(const std::string& name);

		std::string getName()
		{
			return name;
		}

		void addStudent(std::string name, std::vector<Student>& allStudents);


	};

}

#endif
