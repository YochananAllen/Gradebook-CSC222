// Gradebook CSC222.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Yochanan Allen 
// https://github.com/YochananAllen/Gradebook-CSC222.git

//The teacher would like a program to read the student’s names and test scores from a file, calculate
//the average of the test scores and then provide a letter grade for the average.A test data file has
//been provided with six students and five test scores.



#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


double calculateAverage(double scores[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return total / size;
}


char getLetterGrade(double average) {
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

int main() {
    int NUM_STUDENTS, NUM_TESTS;

    
    cout << "Enter the number of students (1 to 6): ";
    cin >> NUM_STUDENTS;

    
    for (; NUM_STUDENTS < 1 || NUM_STUDENTS > 6; ) {
        cout << "Invalid input. Please enter a number between 1 and 6: ";
        cin >> NUM_STUDENTS;
    }

   
    cout << "Enter the number of tests (1 to 5): ";
    cin >> NUM_TESTS;

    
    for (; NUM_TESTS < 1 || NUM_TESTS > 5; ) {
        cout << "Invalid input. Please enter a number between 1 and 5: ";
        cin >> NUM_TESTS;
    }

   
    string* studentNames = new string[NUM_STUDENTS];  
    char* grades = new char[NUM_STUDENTS];             
    double** testScores = new double* [NUM_STUDENTS];   

   
    for (int i = 0; i < NUM_STUDENTS; i++) {
        testScores[i] = new double[NUM_TESTS];
    }

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter the name of student #" << (i + 1) << ": ";
        cin >> studentNames[i];

        cout << "Enter the " << NUM_TESTS << " test scores for " << studentNames[i] << ":" << endl;
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << "Test score #" << (j + 1) << ": ";
            cin >> testScores[i][j];
        }
    }

    
    cout << "\nStudent Scores and Grades:" << endl;
    cout << fixed << setprecision(2);  

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        
        double average = calculateAverage(testScores[i], NUM_TESTS);

      
        grades[i] = getLetterGrade(average);

        
        cout << studentNames[i] << " - Average Score: " << average << " - Grade: " << grades[i] << endl;
    }

  
    for (int i = 0; i < NUM_STUDENTS; i++) {
        delete[] testScores[i];
    }
    delete[] testScores;
    delete[] studentNames;
    delete[] grades;

    return 0;
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
