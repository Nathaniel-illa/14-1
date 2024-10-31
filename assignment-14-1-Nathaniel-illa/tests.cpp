#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "student.hpp"
int Student::NUM_STUDENTS = 0;
double Student::TOTAL_SUM = 0;
// tests for exercise 1

void printS(Student s);

TEST_CASE("Ex1 ", "[Test 1]")
{
	Student s[3];

	double scores1[NUM_SCORES] = {10.23, 99.87, 88.80};
	double scores2[NUM_SCORES] = {50.00, 99.87, 100.00};
	double scores3[NUM_SCORES] = {10.23, 100.00, 88.80};

	s[0] = Student(10001, "John", scores1);
	s[1] = Student(10002, "Bill", scores2);
	s[2] = Student(10003, "Greg", scores3);

	for (int i = 0; i < 3; i++)
		printS(s[i]);

	// cout << " Total number of studetns " << Student::getNumStudents() << endl;
	// cout << " Total sum of studetns " << Student::getTotalScore() << endl;

	REQUIRE(Student::getNumStudents() == 3);
	REQUIRE(Student::getTotalScore() == 647.8);
}

void printS(Student s)
{
	double *sc;
	cout << "ID: " << s.getID() << endl;
	cout << "Name " << s.getName() << endl;
	sc = s.getScores();
	for (int i = 0; i < NUM_SCORES; i++)
		cout << sc[i] << "\t";
	cout << endl;
}