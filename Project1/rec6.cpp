#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TimeSlot
{
	string day;
	int hour;
public:
	TimeSlot(string day = " ", int hour = 0) : day(day), hour(hour) {}
	string getDay()
	{
		return day;
	}

	int getHour()
	{
		return hour;
	}
};
//TimeSlot class
class Student
{
private:
	string name;
	vector<int> grades;
	//vector<int> grades(13,-1);
public:
	Student(string name = " ") : name(name), grades(13, -1) {}

	string getName()
	{
		return name;
	}


	void changeGrade(int index, int newGrade)
	{
		grades[index] = newGrade;
	}

	void display()
	{
		cout << "Student: " << name << "; Grades: ";
		for (size_t i = 0; i < grades.size(); i++)
		{
			cout << grades[i] << " ";
		}
	}
};
//Student class (Student Records)
class Section
{
private:
	string name;
	TimeSlot timeslot;
	
	vector<Student*> allStudents;
public:
	Section(string name = " ", string day = " ", int hour = 0) : name(name), timeslot(day, hour) {}

	/*void loadStudentsFromFile(string fileName)
	{

	}*/

	int NumStudents()
	{
		return allStudents.size();
	}
	string getName()
	{
		return name;
	}

	string getDay()
	{
		return timeslot.getDay();
	}

	int getHour()
	{
		return timeslot.getHour();
	}
	void addStudent(string studentName)
	{
		
		Student* theStudent = new Student(studentName);
		allStudents.push_back(theStudent);
	}

	void removeStudent(string studentName)
	{
		int index = 0;

		for (size_t i = 0; i < allStudents.size(); i++)
		{
			if (allStudents[i]->getName() == studentName)
				index = i;
		}

		for (size_t p = index; p < allStudents.size() - 1; p++)
		{
			allStudents[p] = allStudents[p + 1];
		}

		allStudents.pop_back();
	}

	string getStudentName(int index)
	{
		return allStudents[index]->getName();
	}

	void changeGrade(int student, int week, int grade)
	{
		allStudents[student]->changeGrade(week, grade);
	}

	void display()
	{
		cout << "Section: " << name << "; " << timeslot.getDay() << " ";
		if (timeslot.getHour() < 13)
			cout << timeslot.getHour() << "AM" << endl;
		else
			cout << timeslot.getHour() - 12 << "PM" << endl;

		for (size_t i = 0; i < allStudents.size(); i++)
		{
			allStudents[i]->display();
			cout << endl;
		}

	}

	void reset()
	{
		for (size_t t = 0; t < allStudents.size(); t++)
		{
			
			delete allStudents[t];
		}

		allStudents.clear();
	}

};
//Section class
class LabWorker
{
private:
	string name;
	Section* section;
public:
	LabWorker(string name = " ") : name(name) {}

	void addSection(Section& newSection)
	{
		section = &newSection;
	}

	void addGrade(string studentName, int grade, int week)
	{
		int index = 0;

		for (size_t i = 0; i < section->NumStudents(); i++)
		{
			if (section->getStudentName(i) == studentName)
				index = i;
		}

		section->changeGrade(index, week, grade);

	}

	void displayGrades()
	{
		cout << name << " has Section: " << section->getName() << "; " << section->getDay() << " ";
		if (section->getHour() < 13)
			cout << section->getHour() << "AM" << endl;
		else
			cout << section->getHour() - 12 << "PM" << endl;

		section->display();
	}
};
//Labworker class
int main()
{

	// lab workers
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	// sections and setup and testing
	Section secA2("A2", "Tuesday", 16);
	//secA2.loadStudentsFromFile( "A2.txt" );
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
	secA2.display();
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();

	cin.get();

}