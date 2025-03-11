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

    ifstream inputFile("student_test_scores.txt");//open the input file

    // Step 8: Read student names and test scores
    for (int student = 0; student < MAX_STUDENTS; ++student) { // first loop for
        inputFile >> students_names[student]; // read the student's name and store it in the array students_names

        for (int test = 0; test < MAX_TESTSCORES; ++test) { // 2nd loop for 
            inputFile >> testScores[student][test]; // read the test score and store it in the array testScores
            total[student] += testScores[student][test]; // calcul total of the score and store it in the array total
        }
      average[student] = total[student] / MAX_TESTSCORES; // calcul the average of the scores of the student and store it i the array average
        if (average[student] >= 90) { // condition if to verify if the average is great or equal to 90
          letter_grade[student] = 'A'; // if the condition is true the program add an A to the array note
        } else if (average[student] >= 80) { // condition if to verify if the average is great or equal to 80
          letter_grade[student] = 'B'; // if the condition is true the program add an B to the array note
        } else if (average[student] >= 70) { // condition if to verify if the average is great or equal to 70
          letter_grade[student] = 'C'; // if the condition is true the program add an C to the array note
        } else if (average[student] >= 60) { // condition if to verify if the average is great or equal to 60
          letter_grade[student] = 'D'; // if the condition is true the program add an D to the array note
        } else if (average[student] <60) { // condition if to verify if the average is less than 60
          letter_grade[student] = 'F'; // if the condition is true the program add an F to the array note
        }
    } // end of the 1st loop for

    inputFile.close();// close the input file

      

  cout << left << setw(10) << "Student Name" << right << setw(10) << "Score#1" << right << setw(10) << "Score#2" << right << setw(10) << "Score#3" << right << setw(10) << "Score#4" << right << setw(10) << "Score#5" << right << setw(10) << "Total" << right << setw(10) << "Average " << right << setw(10) << "Grade" << endl; // print the titles
  cout << string(100, '-') << endl; // print the dashes

  for (int student2 = 0; student2 < MAX_STUDENTS; student2++) { // 1st loop for 
      cout << right << setw(11) << students_names[student2]; // print the student's name
      for (int score = 0; score < MAX_TESTSCORES; score++) { // 2nd loop for
          cout << right << setw(10) << testScores[student2][score]; // print the student's test score
      }// end of 2nd loop
      cout << right << setw(10)<< total[student2] << right << setw(10) << average[student2] << right << setw(10) << letter_grade[student2] << endl; // print the student's total, average and letter grade
  }// end of the 1st loop for

  ofstream outputFile("output.txt"); // open a output file call output.txt

    for (int student = 0; student < MAX_STUDENTS; ++student) { // 1st loop for
        outputFile << students_names[student] << " "; // write the student's name
        for (int test = 0; test < MAX_TESTSCORES; ++test) { // 2nd loop for
            outputFile << testScores[student][test] << " "; // write the student's test score in the file
        } // end of the 2nd loop for
        outputFile << total[student] << " " << average[student] << " " << letter_grade[student] << endl; // write the total, the average and the letter grade of the student
    } // end of the 1st loop for

    outputFile.close(); // close the output file

    return 0; // send 0 back to operating system
  }// end of the function main