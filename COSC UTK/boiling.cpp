/* Program Name: Boiling Water
 * Student Name: Ariel Thompson
 * Program Description: The Boiling Water Program prompts the user to select a city and calculates the boiling point
 *  of the city based on the city's altitude.*/

#include <cmath> // new: for pow and log
#include <fstream>
#include <iostream>
#include <sstream> // new: for istringstream
#include <string>
#include <vector>

using namespace std;

// Calculates the boiling point of the city based on elevation (altitude)
double elevationToBoilingPoint(const double elevation) {

  double boilingPoint = 0.0;
  double pressure = 0.0;

  pressure = 29.921 * pow((1 - 0.0000068753 * elevation), 5.2559);
  boilingPoint = 49.161 * log(pressure) + 44.932;

  return boilingPoint;
}

int main(int argc, char **argv) {

  // Declares needed variables for the fstream input and to calculate boiling point
  string indvCityName, stateInitial, firstLine, indvCityAltitude;
  int cityNumber;
  double finalBoilingPoint;

  // Declares vectors for city's name and altitude
  vector<string> cityName;
  vector<int> cityAltitude;

  // Error checks number of arguments
  if (argc != 2){

    cerr << "usage: ./boiling filename" << endl;
    return 1;
  }

  // Declares fstream, csvFilename, and opens the file
  ifstream fin;
  string csvFilename = argv[1];
  fin.open(csvFilename);

  // Error checks if file opens
  if (!(fin.is_open())){
    
    cerr << "File failed to open." << endl;
    return 1;
  }

  // Prints out title
  cout << "Boiling Point at Altitude Calculator" << endl;

  getline(fin, firstLine); // Using getline to skip the first row of csv file

  // Reads the city name, state initial, and city altitude from file
  while (getline(fin, firstLine)){
    
    istringstream sin(firstLine);
    getline(sin, indvCityName, ',');
    getline(sin, stateInitial, ',');
    getline(sin, indvCityAltitude, ',');

    // Adds read city name and altitude to respective vectors
    cityName.push_back(indvCityName);
    cityAltitude.push_back(stoi(indvCityAltitude));
    // prints out selection of cities
    cout << cityName.size() << ". " << indvCityName << endl;
  }

  // Prompts user to enter city number
  cout << "Enter city number: ";
  cin >> cityNumber;
  // calls method to calculate boiling point
  finalBoilingPoint = elevationToBoilingPoint(double(cityAltitude[cityNumber - 1]));

  // prints out result statement
  cout << "The boiling point at " << cityName[cityNumber - 1] << " is " << finalBoilingPoint << " degrees Fahrenheit." << endl;

  // closes file
  fin.close(); 

  return 0;
}
