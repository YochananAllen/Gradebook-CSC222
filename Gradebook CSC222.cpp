// Gradebook CSC222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Yochanan Allen 
// https://github.com/YochananAllen/Gradebook-CSC222.git

//The teacher would like a program to read the student’s names and test scores from a file, calculate
//the average of the test scores and then provide a letter grade for the average.A test data file has
//been provided with six students and five test scores.



#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_TESTS = 5; 
const int MAX_STUDENTS = 6; 


void calculateAverages(int scores[][NUM_TESTS], double averages[], int numStudents);
char calculateLetterGrade(double average);
void produceReport(string names[], double averages[], int numStudents);

int main() {
    
    string names[MAX_STUDENTS] = {
        "Aaliyah", "Briana", "Devon", "Javier", "Johnathan", "Vanessa"
    };

    int scores[MAX_STUDENTS][NUM_TESTS] = {
        {82, 72, 91, 74, 82},
        {87, 97, 82, 92, 94},
        {92, 98, 91, 100, 85},
        {85, 82, 72, 84, 85},
        {78, 60, 63, 79, 81},
        {74, 91, 77, 74, 80}
    };

    double averages[MAX_STUDENTS]; 

    
    calculateAverages(scores, averages, MAX_STUDENTS);

    
    produceReport(names, averages, MAX_STUDENTS);

    return 0;
}


void calculateAverages(int scores[][NUM_TESTS], double averages[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = static_cast<double>(sum) / NUM_TESTS; 
    }
}


char calculateLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

void produceReport(string names[], double averages[], int numStudents) {
    cout << left << setw(20) << "Student Name"
        << setw(10) << "Average"
        << setw(10) << "Grade" << endl;

   

    for (int i = 0; i < numStudents; i++) {
        char grade = calculateLetterGrade(averages[i]);
        cout << left << setw(20) << names[i]
            << setw(10) << fixed << setprecision(2) << averages[i]
            << setw(10) << grade << endl;
    }
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
