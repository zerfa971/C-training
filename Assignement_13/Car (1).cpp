#include "Car.h" // include the header file
#include <iostream>// Inclusion of the iostream library (for input/output)
using namespace std;// Use of the standard namespace

Car::Car() : year(0), price(0.0) {} // Default constructor


Car::Car(const string& make, const string& model, int year, double price)
    : make(make), model(model), year(year), price(price) {} // Parameterized constructor

// Setters and getters for attributes
void Car::setMake(const string& make) { // Setter for make
    this->make = make; // Set the make attribute to the value of the parameter
} // End of setter for make

string Car::getMake() const { // Getter for make
    return make; // Return the value of the make attribute
} // End of getter for make

void Car::setModel(const string& model) { // Setter for model
    this->model = model; // Set the model attribute to the value of the parameter
} // End of setter for model

string Car::getModel() const { // Getter for model
    return model; // Return the value of the model attribute
} // End of getter for model

void Car::setYear(int year) { // Setter for year
    this->year = year; // Set the year attribute to the value of the parameter
} // End of setter for year

int Car::getYear() const { // Getter for year
    return year; // Return the value of the year attribute
} // End of getter for year

void Car::setPrice(double price) { // Setter for price
    this->price = price; // Set the price attribute to the value of the parameter
} // End of setter for price

double Car::getPrice() const { // Getter for price
    return price; // Return the value of the price attribute
} // End of getter for price

void Car::displayInfo() const { // subfunctions to display the informations about the car
    cout << "Make: " << make << endl;// Display the Make of the car
    cout << "Model: " << model << endl;// Display the Model of the car
    cout << "Year: " << year << endl;// Display the Year of the car
    cout << "Price: $" << price << endl;// Display the Price of the car
} // End of displayInfo function