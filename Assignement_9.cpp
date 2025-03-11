/*
Nolan Berthe
10/19/2023
CM 210-01
Fall2023
Freshman student
Assignment 9
This program was written by, Nolan Berthe.
Input= This program ask to the user to enter a name and the age of the student with the command cout and store the answers with cin
Output = This program display every name, their age and the total of ages and the average of the ages
Processing =  To first this program create 1 int variable called MAX_ITEMS for the maximum number of items, 1 array string called names to store the names, 1 array int called ages to store the ages, 2 decimal variable spaces called total to store the total of the ages and average to store the average of the ages. Then this program create a loop for and ask the user to enter a name and age and store the answers with cin. 2nd loop for to calculate the total of the ages. Then calculate the average. Finally the program create another loop for to print every names, with their ages, and at the end the total and the average.*/

#include <iostream>// Inclusion of the iostream library (for input/output)
#include <iomanip>// Inclusion of the iomanip library (for place the elements correctly))
using namespace std; // Use of the standard namespace

int main() //funtion called main
{// beginning of the function main
  const int MAX_ITEMS = 10; // create a variable space for the maximum number of items
  string names[MAX_ITEMS]; // create a array string to store the names
  int ages[MAX_ITEMS];// create a array numbers to store the ages
  double total = 0; // create a decimal variable space for the total
  double average = 0; // create a decimal variable space for the average

  for (int i = 0; i < MAX_ITEMS; i++) // loop for
  { // beginning of the loop for
      cout << "Enter a name: ";// Ask for the user to enter a name
      cin >> names[i]; // Store the name in the array names

      // Ask for the user to enter the age for the entered name
      cout << "Enter " << names[i] << "'s age: "; // Ask for the user to enter the age for the entered name
      cin >> ages[i];// Store the age in the array ages

  }// end of the loop for

  for (int i = 0; i < MAX_ITEMS; i++) // loop for
    { // beginning of the loop for
      total += ages[i];// Add the age to the variable total
    } // end of the loop for
  
  average = total / MAX_ITEMS;// Calculate the average of the ages
  
  for (int i = 0; i < MAX_ITEMS; i++) // loop for
  { //beginning of the loop for
    cout << right << setw(10) << names[i] << right << setw(7) << ages[i] << endl; // display the name and their age
  } // end of the loop for
  cout << string(20, '-') << endl; // print the dashes
  // Display total and average age
  cout << right << setw(10) << "total" << right << setw(7) << total << endl; // display the total
  cout << right << setw(10) << "Average " << right << setw(10) << average << endl; // display the average
  
  return 0; // return 0 to the operating system
}// end of the function main
