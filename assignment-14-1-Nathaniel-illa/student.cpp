#include "student.hpp"

int Student::NUM_STUDENTS = 0;
double Student::TOTAL_SUM = 0.0;

// Default Constructor
Student::Student() : sid(0), sname("") {
    for (int i = 0; i < NUM_SCORES; i++) {
        scores[i] = 0.0;
    }
}

// Parameterized Constructor
Student::Student(int id, string name, double *sc) : sid(id), sname(name) {
    double scoreSum = 0.0;
    for (int i = 0; i < NUM_SCORES; i++) {
        scores[i] = sc[i];
        scoreSum += scores[i];
    }
    TOTAL_SUM += scoreSum;
    if (scoreSum > 250) {
        NUM_STUDENTS++;
    }
}

// Getters
int Student::getID() const {
    return sid;
}

string Student::getName() const {
    return sname;
}

const double* Student::getScores() const {
    return scores;
}

// Setters
void Student::setID(int id) {
    sid = id;
}

void Student::setName(string name) {
    sname = name;
}

void Student::setScores(double *sc) {
    double oldSum = 0.0;
    double newSum = 0.0;

    for (int i = 0; i < NUM_SCORES; i++) {
        oldSum += scores[i];
    }

    for (int i = 0; i < NUM_SCORES; i++) {
        scores[i] = sc[i];
        newSum += scores[i];
    }

    TOTAL_SUM += (newSum - oldSum);

    if (oldSum <= 250 && newSum > 250) {
        NUM_STUDENTS++;
    } else if (oldSum > 250 && newSum <= 250) {
        NUM_STUDENTS--;
    }
}

// Static functions
int Student::getNumStudents() {
    return NUM_STUDENTS;
}

double Student::getTotalScore() {
    return TOTAL_SUM;
}