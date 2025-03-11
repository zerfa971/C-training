/*
Nolan Berthe
11/17/2023
CM 210-01
Fall2023
Freshman student
Assignment 13
This program Assignment#13 was written by, Nolan Berthe.
Input =  The values of the attributes of the Car class (make, model, year, price) are defined when a Car object is created in the main function (main) of the CarMain.cpp file.
Processing = The Car.h file specifies the Car class with its attributes and methods.
The Car.cpp file implements the definitions of the Car class methods.
The CarMain.cpp file uses the Car class by creating an object and calling its methods.
Output = This program displays the characteristics of the car, such as make, model, year and price.
*/
#include "Car.h"// Include the header file for the Car class
#include <iostream>// Inclusion of the iostream library (for input/output)
using namespace std;// Use of the standard namespace

int main() { // Start of the main function
    Car car1("Mercedes", "Benz", 2023, 62995);// Create objects of the Car class
    Car car2("Audi", "RS5 2.9T", 2023, 73998);// Create objects of the Car class with parameters

    car1.displayInfo(); // Call the displayInfo() function for car1
    cout << endl; // Print a newline character

    car2.displayInfo();// Call the displayInfo() function for car2

    return 0; // Return 0 to indicate successful program execution
} // end of the function main