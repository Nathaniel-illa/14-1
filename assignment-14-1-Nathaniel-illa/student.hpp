#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

#define NUM_SCORES 3

class Student {
private:
    int sid;
    string sname;
    double scores[NUM_SCORES];
    static int NUM_STUDENTS;
    static double TOTAL_SUM;

public:
    // Constructors
    Student();
    Student(int id, string name, double *sc);

    // Getter functions
    int getID() const;
    string getName() const;
    const double* getScores() const;

    // Setter functions
    void setID(int id);
    void setName(string name);
    void setScores(double *sc);

    // Static functions
    static int getNumStudents();
    static double getTotalScore();
};

#endif // STUDENT_HPP