/* Program Name: Take Home Pay
 * Student Name: Lauren Thompson
 * Program Description: This program takes a users inputted anual salary and calculates
 * their take home salary (post-tax) and their monthly take home pay.
 *  */

#include <iostream>
#include <iomanip>

using namespace std;

//defines minimum wage as of 2022
const double MINIMUM_WAGE = 15080;

int main(){
	
	//inputs salary
	double salary;
	cout << "Enter a salary: $";
	cin >> salary;

	//defines medicare and social security tax (with flat rates already given)
	//defines the rest of the needed variables
	double medicareTax = 0.0145 * salary;
	double socialSecurityTax = 0.062 * salary;
	double incomeTax, takeHomeSalary, monthlyTakeHomeSalary;

	//outputs error message if salary is less than minimum wage
	if(salary <= MINIMUM_WAGE) {
		cerr << "This is less than minimum wage for a yearly salary." << endl;
		return 1;
	}

	//calculates income tax using given 2022 tax brackets
	//starts with the highest tax bracket and staggers from there
	if(salary >= 539901){
		incomeTax = (salary - 539900) * 0.37;
		incomeTax += (539900 - 215950) * 0.35;
		incomeTax += (215950 - 170050) * 0.32;
		incomeTax += (170050 - 89075) * 0.24;
		incomeTax += (89075 - 41775) * 0.22;
		incomeTax += (41775 - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 539900 && salary >= 215951){
		incomeTax = (salary - 215950) * 0.35;
		incomeTax += (215950 - 170050) * 0.32;
		incomeTax += (170050 - 89075) * 0.24;
		incomeTax += (89075 - 41775) * 0.22;
		incomeTax += (41775 - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 215950 && salary >= 170051){
		incomeTax = (salary - 170050) * 0.32;
		incomeTax += (170050 - 89075) * 0.24;
		incomeTax += (89075 - 41775) * 0.22;
		incomeTax += (41775 - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 170050 && salary >= 89076){
		incomeTax = (salary - 89075) * 0.24;
		incomeTax += (89075 - 41775) * 0.22;
		incomeTax += (41775 - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 89075 && salary >= 41776){
		incomeTax = (salary - 41775) * 0.22;
		incomeTax += (41775 - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 41775 && salary >= 10276){	
		incomeTax = (salary - 10275) * 0.12;
		incomeTax += (10275 * 0.10);

	} else if (salary <= 10275){	
		incomeTax += (10275 * 0.10);

	}

	//calculates take home salary and monthly take home salary
	takeHomeSalary = salary - (medicareTax + socialSecurityTax + incomeTax);
	monthlyTakeHomeSalary = takeHomeSalary / 12;
	
	//sets up the first line of output - entered salary & seperating dashed lines
	cout << string(35, '-') << endl;
	cout << left << setw(25) << setprecision(2) << fixed << "Yearly Salary: ";
	cout << right << "$" << setw(9) << salary << endl;

	//social security tax output
	cout << left << setw(25) << "Social Security Tax: ";
	cout << right << "$" << setw(9) << socialSecurityTax << endl;

	//medicare tax output
	cout << left << setw(25) << "Medicare Tax: ";
	cout << right << "$" << setw(9) << medicareTax << endl;

	//income tax output
	cout << left << setw(25) << "Income Tax: ";
	cout << right << "$" << setw(9) << incomeTax << endl;

	//dividing dash line with take home salary output
	cout << string(35, '-') << endl;
	cout << left << setw(25) << "Take Home Salary: ";
	cout << right << "$" << setw(9) << takeHomeSalary << endl;

	//monthly take home salary output
	cout << left << setw(25) << "Monthly Take Home Pay: ";
	cout << right << "$" << setw(9) << monthlyTakeHomeSalary << endl;

	return 0;
}

