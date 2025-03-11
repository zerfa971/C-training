/*
Nolan Berthe
11/3/2023
CM 210-01
Fall2023
Freshman student
Assignment 11
This program was written by, Nolan Berthe.
Input = This program reads the information from the txt file student_test_scores and stores it in the right places in the arrays.
Output = This program prints 9 headings: Student name, Score#1, Score#2, Score#3, Score#4, Score#5, Total, Average, Grade. It then prints the result of all these titles, using cout and iomanip library commands to place the elements correctly. And write  the answers in the file output.txt
Processing = To begin with, we create 2 int variables for the maximum number of student names and the maximum number of test grades, then create a string array to store the student name. Next, we create 1 int array to store the student grades, 2 double variables to store the total and average and 1 string array to store the grade.  Next, we create a for loop (3 passages) to read the student's name and store the answer in the name array. Next, we create a second for loop in the first for loop (5 passages) to read the student's marks from the file and store them in the marks array and add the answer to the total array. Next, we calculate the average by dividing the total by 5 and store the result in the average array. Next, we use the if and elif statements to compare the results and find the grade. Then, we print the title, the student's name, the grades, the total, the average and the grade. And underneath the result of all these titles, using cout and iomanip library commands to place the elements correctly. Finally We open a output file called output.txt and we write all of the answers with the loop for then we close the file.
*/
#include <iostream>// Inclusion of the iostream library (for input/output)
#include <fstream>// Inclusion of the fstream library (for read a txt file)
#include <iomanip>// Inclusion of the iomanip library (for place the elements correctly)
using namespace std; // Use of the standard namespace

int main() { //beginning of the function main
    const int MAX_STUDENTS = 3;// create a variable space for the maximum number of students
    const int MAX_TESTSCORES = 5;// create a variable space for the maximum number of test scores
    string students_names[MAX_STUDENTS];// create a array string for the student's names
    double testScores[MAX_STUDENTS][MAX_TESTSCORES];// create a array for the student's scores
    double total[MAX_STUDENTS] = {0};// create a array to store the total of the scores of every students
    double average[MAX_STUDENTS] = {0};// create a array to store the average of the scores of every students
    string letter_grade[MAX_STUDENTS];// create a array to store the letter grade of every students
    // Function prototypes
    void inputFunction(string names[], int testScores[][MAX_TESTSCORES]);
    void processFunction(string names[], int testScores[][MAX_TESTSCORES], int total[], double average[], string letterGrades[]);
    void outputFunction(string names[], int testScores[][MAX_TESTSCORES], int total[], double average[], string letterGrades[]);


    ifstream inputFile("student_test_scores.txt");//open the input file
    ofstream outputFile("output.txt");//open the output file

    // Step 9: Call input function
    inputFunction(names, testScores);

    // Step 10: Call process function
    processFunction(names, testScores, total, average, letterGrades);

    // Step 11: Call output function
    outputFunction(names, testScores, total, average, letterGrades);

    // Close files
    inputFile.close();
    outputFile.close();

  // Step 9: Input function
  void inputFunction(string names[], int testScores[][MAX_TESTSCORES]) {
      ifstream inputFile("input.txt");

      for (int i = 0; i < MAX_STUDENTS; ++i) {
          inputFile >> names[i];

          for (int j = 0; j < MAX_TESTSCORES; ++j) {
              inputFile >> testScores[i][j];
          }
      }

      inputFile.close();
  }

  // Step 10: Process function
  void processFunction(string names[], int testScores[][MAX_TESTSCORES], int total[], double average[], string letterGrades[]) {
      for (int i = 0; i < MAX_STUDENTS; ++i) {
          for (int j = 0; j < MAX_TESTSCORES; ++j) {
              total[i] += testScores[i][j];
          }

          average[i] = static_cast<double>(total[i]) / MAX_TESTSCORES;

          // Calculate letter grade (you can customize this part based on your grading criteria)
          if (average[i] >= 90) {
              letterGrades[i] = "A";
          } else if (average[i] >= 80) {
              letterGrades[i] = "B";
          } else if (average[i] >= 70) {
              letterGrades[i] = "C";
          } else if (average[i] >= 60) {
              letterGrades[i] = "D";
          } else {
              letterGrades[i] = "F";
          }
      }
  }

  // Step 11: Output function
  void outputFunction(string names[], int testScores[][MAX_TESTSCORES], int total[], double average[], string letterGrades[]) {
      // Display column header
      cout << setw(15) << "Student Name";
      for (int i = 1; i <= MAX_TESTSCORES; ++i) {
          cout << setw(10) << "Test " << i;
      }
      cout << setw(10) << "Total" << setw(15) << "Average" << setw(10) << "Grade" << endl;

      // Open output file
      ofstream outputFile("output.txt");

      // Write column header to the output file
      outputFile << setw(15) << "Student Name";
      for (int i = 1; i <= MAX_TESTSCORES; ++i) {
          outputFile << setw(10) << "Test " << i;
      }
      outputFile << setw(10) << "Total" << setw(15) << "Average" << setw(10) << "Grade" << endl;

      // Display and write the rest of the output
      for (int i = 0; i < MAX_STUDENTS; ++i) {
          cout << setw(15) << names[i];
          outputFile << setw(15) << names[i];

          for (int j = 0; j < MAX_TESTSCORES; ++j) {
              cout << setw(10) << testScores[i][j];
              outputFile << setw(10) << testScores[i][j];
          }

          cout << setw(10) << total[i] << setw(15) << fixed << setprecision(2) << average[i] << setw(10) << letterGrades[i] << endl;
          outputFile << setw(10) << total[i] << setw(15) << fixed << setprecision(2) << average[i] << setw(10) << letterGrades[i] << endl;
      }

      // Close the output file
      outputFile.close();
  }