#ifndef CAR_H // If the CAR_H identifier is not defined
#define CAR_H // Define CAR_H to avoid multiple inclusion
#include <string> // Include the string header file for using string data type
using namespace std;// Use of the standard namespace

class Car { // create the class car
private: // Declare private access specifier for the following attributes
    string make; //Attribute make
    string model; //Attribute model
    int year; //Attribute year
    double price; //Attribute price

public: // Declare public access specifier for the following members
    // Constructors
    Car();  // Default constructor
    Car(const string& make, const string& model, int year, double price);  // Parameterized constructor

    void setMake(const string& make); // Set the make of the car
    string getMake() const; // Get the make of the car

    void setModel(const string& model); // Set the model of the car
    string getModel() const; // Get the model of the car

    void setYear(int year); // Set the manufacturing year of the car
    int getYear() const; // Get the manufacturing year of the car

    void setPrice(double price); // Set the price of the car
    double getPrice() const; // Get the price of the car

    void displayInfo() const; // Display information about the car
}; // // End of the Car class declaration

#endif // CAR_H