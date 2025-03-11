/*
Nolan Berthe
11/10/2023
CM 210-01
Fall2023
Freshman student
Assignment 12
This program was written by, Nolan Berthe.
Input = This program reads the information from the txt file student_test_scores and stores it in the right places in the arrays.
Output = This program prints 9 headings: Student name, Score#1, Score#2, Score#3, Score#4, Score#5, Total, Average, Grade. It then prints the result of all these titles, using cout and iomanip library commands to place the elements correctly. And write  the answers in the file output.txt
Processing = To begin with, we create 2 int variables for the maximum number of student names and the maximum number of test grades,then we create 3 function prototypes called: inputFunction, processFunction and outputFunction, then create a string array to store the student name. Next, we create 1 int array to store the student grades, 2 double variables to store the total and average and 1 string array to store the grade. We open the input file and the output file then we calling the 3 subfunctions, and we finish the function main by closed the input and output file. We write the first subfunction called inputFunction, which is used to read the input file and store the information in the arrays. We also write the second subfunction called processFunction, which is used to calculate the total and average of the student grades. And to finish we write the third subfunction called outputFunction, which is used to print the headings and the results of the calculations.
*/
#include <iostream>// Inclusion of the iostream library (for input/output)
#include <fstream>// Inclusion of the fstream library (for read a txt file)
#include <iomanip>// Inclusion of the iomanip library (for place the elements correctly)
#include <string>// Inclusion of the string library (for string variables)

using namespace std;// Use of the standard namespace

const int MAX_STUDENTS = 3;// create a variable space for the maximum number of students
const int MAX_TESTSCORES = 5;// create a variable space for the maximum number of test scores


void inputFunction(string studentNames[], int testScores[MAX_STUDENTS][MAX_TESTSCORES], ifstream& inputFile); // Function prototypes
void processFunction(int testScores[MAX_STUDENTS][MAX_TESTSCORES], double totalScores[MAX_STUDENTS], // Function prototypes
                     double averageScores[MAX_STUDENTS], string letterGrades[MAX_STUDENTS]);
void outputFunction(string studentNames[], int testScores[MAX_STUDENTS][MAX_TESTSCORES],// Function prototypes 
                     double totalScores[MAX_STUDENTS], double averageScores[MAX_STUDENTS],
                     string letterGrades[MAX_STUDENTS], ofstream& outputFile);

int main() { // Start of the main function
    string studentNames[MAX_STUDENTS]; // create a array string for the student's names
    int testScores[MAX_STUDENTS][MAX_TESTSCORES]; // create a array for the student's scores
    double totalScores[MAX_STUDENTS] = {0};// create a array to store the total of the scores of every students
    double averageScores[MAX_STUDENTS] = {0};// create a array to store the average of the scores of every students
    string letterGrades[MAX_STUDENTS];// create a array to store the letter grade of every students

    ifstream inputFile("input.txt");  // Replace "input.txt" with your input file name

    ofstream outputFile("output.txt");  // Replace "output.txt" with your output file name

    inputFunction(studentNames, testScores, inputFile); //Calling the subfunction

    processFunction(testScores, totalScores, averageScores, letterGrades);// Calling the processFunction

    outputFunction(studentNames, testScores, totalScores, averageScores, letterGrades, outputFile);// Calling the outputFunction

    inputFile.close();// close the input file
    outputFile.close();// close the output file

    return 0; // return 0 to the operating system
} // End of the main function


void inputFunction(string studentNames[], int testScores[MAX_STUDENTS][MAX_TESTSCORES], ifstream& inputFile) { // Definition of the inputFunction
    for (int i = 0; i < MAX_STUDENTS; ++i) { // Start of the for loop
        inputFile >> studentNames[i]; // Read the student's name from the input file
        for (int j = 0; j < MAX_TESTSCORES; ++j) { // Start of the nested for loop
            inputFile >> testScores[i][j]; // Read the student's score from the input file
        } // End of the nested for loop
    } // End of the for loop
} // End of the inputFunction

void processFunction(int testScores[MAX_STUDENTS][MAX_TESTSCORES], double totalScores[MAX_STUDENTS], // Definition of the processFunction
                     double averageScores[MAX_STUDENTS], string letterGrades[MAX_STUDENTS]) {
    for (int i = 0; i < MAX_STUDENTS; ++i) { // Start of the 1st for loop
        for (int j = 0; j < MAX_TESTSCORES; ++j) { // Start of the 2nd for loop
            totalScores[i] += testScores[i][j]; // Calculate the total score of every students
        } // end of the second loop for

        averageScores[i] = totalScores[i] / MAX_TESTSCORES; // Calculate the average score of every students

        if (averageScores[i] >= 90) { // if the average score is greater than or equal to 90
            letterGrades[i] = "A"; // assign the letter grade A to the student
        } else if (averageScores[i] >= 80) { // if the average score is greater than or equal to 80
            letterGrades[i] = "B"; // assign the letter grade B to the student
        } else if (averageScores[i] >= 70) { // if the average score is greater than or equal to 70
            letterGrades[i] = "C"; // assign the letter grade C to the student
        } else if (averageScores[i] >= 60) { // if the average score is greater than or equal to 60
            letterGrades[i] = "D"; // assign the letter grade D to the student
        } else { // if the average score is less than 60
            letterGrades[i] = "F"; // assign the letter grade F to the student
        } // end of the if-else statement
    } // end of the 1st for loop
} // end of the processFunction

void outputFunction(string studentNames[], int testScores[MAX_STUDENTS][MAX_TESTSCORES], // Definition of the outputFunction
                     double totalScores[MAX_STUDENTS], double averageScores[MAX_STUDENTS],
                     string letterGrades[MAX_STUDENTS], ofstream& outputFile) {
  
    cout << left << setw(10) << "Student Name" << right << setw(10) << "Score#1" << right << setw(10) << "Score#2" << right << setw(10) << "Score#3" << right << setw(10) << "Score#4" << right << setw(10) << "Score#5" << right << setw(8) << "Total" << right << setw(10) << "Average " << right << setw(10) << "Grade" << endl; // print the titles
    cout << string(100, '-') << endl; // print the dashes

    for (int i = 0; i < MAX_STUDENTS; ++i) { // Start of the 1st for loop
        cout << setw(10) << studentNames[i]; // print the student's name
        outputFile << studentNames[i]; // print the student's name in the output file
        for (int j = 0; j < MAX_TESTSCORES; ++j) { // Start of the 2nd for loop
            cout << setw(10) << testScores[i][j]; // print the student's score
            outputFile << " " << testScores[i][j]; // print the student's score in the output file
        } // end of the 2nd for loop

      cout << right << setw(10) << fixed << setprecision(2) << totalScores[i] << right << setw(10) << fixed << setprecision(2) << averageScores[i] << right << setw(10) << letterGrades[i] << endl; // print the total score and average score and letter grade
        outputFile << " " << totalScores[i] << " " << averageScores[i] << " " << letterGrades[i] << endl; // print the total score and average score and letter grade in the output file
    } // end of the first loop for
}// end of the subfunction
