/* Program Name: Penname
 * Student Name: Lauren Thompson
 * Program Description: The penname.cpp program takes your current information such as your first name, middle name, age, street address, and
 * birth city and generates random penname information for use.
 */

#include <iostream>
using namespace std;

int main(){
	string firstName, middleName;
	int age;
	int streetNumber;
	string streetName, streetType;
	string birthCity;

	cout << "Enter your first and middle names:  " << endl;
	cin >> firstName >> middleName;

	cout << "Enter your age: " << endl;
	cin >> age;

	cout << "Enter your street number, name, and type: " << endl;
	cin >> streetNumber >> streetName >> streetType;

	cout << "Enter your city of birth: " << endl;
	cin >> birthCity;

	int pennameAge = (streetNumber % age) * 3;
	int pennameStreetNumber = (age * 425) / streetNumber;

	cout << "Your penname name is " << birthCity << " " << streetName << "." << endl;
	cout << "You will write as a " << pennameAge << " year old." << endl;
	cout << "Your address is " << pennameStreetNumber << " " << middleName << " " << streetType << "." << endl;
}
