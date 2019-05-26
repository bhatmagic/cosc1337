// Copyright 2019 David Boyd
#include <iostream>
#include <string>
#include <iomanip>

//===============
//=== Structs ===
//===============
struct Student {
    int grade,
        strLen;  // used for display-format
    std::string name;
};

//======================
//=== Fns Prototypes ===
//======================
double calcAverage(Student *, int);
void   displayResults(Student *, int, double);
void   getGrades(Student *, int);
void   getLongestName(Student *, int);
void   getNames(Student *, int);
int    getNumStudents();
void   sortGrades(Student *, int);

//============
//=== Main ===
//============
int main () {

    Student *classroom = nullptr;
    int nStudents;
    double average;

    // Get number of students 
    nStudents = getNumStudents();
    std::cout << std::endl;
    
    // Dynamically allocate an array large enough
    // to hold number of students
    classroom = new Student[nStudents];  // Allocate memory 

    // Get student data
    getNames(classroom, nStudents);
    std::cout << std::endl;
    getLongestName(classroom, nStudents);
    getGrades(classroom, nStudents);
    std::cout << std::endl;

    // Bubble sort array based on student grades
    sortGrades(classroom, nStudents);

    // Calculate the total grades
    average = calcAverage(classroom, nStudents);

    // Display the results
    displayResults(classroom, nStudents, average);
    std::cout << std::endl;

    // Free dynamically allocated memory
    delete [] classroom;
    classroom = nullptr;

    return 0;
}

//=======================
//=== Fns Definitions ===
//=======================
//--- Average ------------------------------------------------------------------
double calcAverage(Student *s, int size) {
    double total = 0.0;
    for (int count = 0; count < size; ++count) {
        total += s[count].grade;
    }
    return (total / size);
}

//--- Display Results ----------------------------------------------------------
void displayResults(Student *s, int size, double avg) {
    int w1 = s[0].strLen;
    int w2 =  6;  // char width for averages
    char dash = '-';

    // Format Numbers
    std::cout << std::setprecision(1) << std::fixed << std::showpoint;

    // Print Menu
    std::cout << std::setw(w1) << std::left << "Name" 
              << std::setw(w2) << std::right << "Score" << std::endl;
    // Print border
    for (int i=0; i<(w1+w2); ++i) {
        std::cout << dash;
    } 
    std::cout << std::endl;
    // Print Students and Grades
    for (int count = 0; count < size; ++count) {
        std::cout << std::setw(w1) << std::left << s[count].name 
                  << std::setw(w2) << std::right << s[count].grade << std::endl;
        }
    // Print border
    for (int i=0; i<(w1+w2); ++i) {
        std::cout << dash;
    } 
    std::cout << std::endl;
    // Print Average
    std::cout << std::setw(w1) << std::left << "Average" 
                  << std::setw(w2) << std::right << avg << std::endl;
}

//--- Get Student Grades -------------------------------------------------------
void getGrades(Student *s, int size) {
    int w1 = s[0].strLen;
    std::cout << "Enter the grades below." << std::endl;
    for (int i=0; i<size; ++i) {
        do {  // validate grades between 0 and 105
            std::cout << std::setw(w1) << std::left << s[i].name << ": ";
            std::cin  >> s[i].grade;
            if (s[i].grade < 0 || s[i].grade > 105) {
                std::cout << "\nGrades must be between 0 and 105\n";
            }
        } while (s[i].grade < 0 || s[i].grade > 105);
    }
}

//--- Get Student Names --------------------------------------------------------
void getNames(Student *s, int size) {
    std::cout << "Enter the names below." << std::endl;
    std::cin.ignore();
    for (int count = 0; count < size; ++count) {
        std::cout << "Student " << (count + 1) << ": ";
        std::getline(std::cin, s[count].name);
    }
}

//--- Get Number of Students ---------------------------------------------------
int getNumStudents() {
    int numOfStudents;
    std::cout << "How many students do you wish to process? ";
    std::cin  >> numOfStudents;
    return numOfStudents;
}

//--- Find Longest Name --------------------------------------------------------
void getLongestName(Student *s, int size) {
    int w1 = s[0].name.length();
    for (int i=0; i<size; ++i) {
       if (w1 < s[i].name.length()) {
            w1 = s[i].name.length();
       }
    }
    s[0].strLen = w1;
}

//--- Sort Grades --------------------------------------------------------------
void sortGrades(Student *s, int size) {
    Student temp;   // Holds a Student object
    bool swap;
    do {
        swap = false;
        for (int count = 0; count < (size-1); ++count) {
            if (s[count].grade > s[count+1].grade) {
                temp.grade = s[count].grade;
                temp.name = s[count].name;
                s[count].grade = s[count+1].grade;
                s[count].name = s[count+1].name;
                s[count+1].grade = temp.grade;
                s[count+1].name = temp.name;
                swap = true;
            }
        }
    } while (swap);
}
