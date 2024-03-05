/* Program Name: Speeding Ticket Calculator
 * Student Name: Ariel Thompson
 * Net ID: NETID athom211
 * Student ID: 000-66-6497
 * Program Description: The speeding ticket calculator program takes a input ticket file, produced by a police database
 * and creates a formatted output file that prints the date, ticket number, and the calculated ticket fee total. */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// constant string array list of months abbreviated to three letters
const string THREE_LETTER_MONTHS[] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

// defines the ticket fee multipliers as well as the minimum fine amount
const double INTERSTATE_MULTIPLIER = 5.2243;
const double HIGHWAY_MULTIPLIER = 9.4312;
const double RESIDENTIAL_MULTIPLIER = 17.2537;
const double DEFAULT_MULTIPLIER = 12.916;
const double MINIMUM_FINE = 0.00;

// combines the month, day, and year into a single integer in the form YYYYMMDD
int serializeDate(const int year, const int month, const int day) {
  
  int serialDate;
  serialDate = stoi(to_string(year) + to_string(month) + to_string(day));

  return serialDate;

}

int main() {
 
  // defined variables: file naming, variables to calculate fine, start dates, end dates
  // and input dates
  string inputFileName, outputFileName, citationNumber;

  int clockedSpeed, speedLimit, initialFine;
  char roadType;
  double finalFine;

  int startMonth, startDay, startYear, startDate;
  int endMonth, endDay, endYear, endDate;
  int inputMonth, inputDay, inputYear, serialInputDate;

  // defines input stream (fin) and output stream (fout)
  ifstream fin(inputFileName);
  ofstream fout(outputFileName);

  //prompts user for input ticket file
  cout << "Enter a ticket file: ";
  cin >> inputFileName;

  //opens input file
  fin.open(inputFileName);

  //displays error message if input file does not open
  if (!(fin.is_open())){
    cerr << "Unable to open bad-ticket-filename." << endl;
    return 1;
  }

  //prompts user for output ticket file
  cout << "Enter a report file: ";
  cin >> outputFileName;

  //opens output file
  fout.open(outputFileName);

  //displays error message if output file does not open
  if(!(fout.is_open())){
    cerr << "Unable to open bad/report/path/bad-report-filename." << endl;
    return 1;
  }

  //prompts user for a start date
  cout << "Enter report start date (mm dd yyyy): ";
  cin >> startMonth >> startDay >> startYear;

  //reformats start date
  startDate = serializeDate(startYear, startMonth, startDay);

  //prompts user for an end date
  cout << "Enter report end date   (mm dd yyyy): ";
  cin >> endMonth >> endDay >> endYear;
  
  //reformats end date
  endDate = serializeDate(endYear, endMonth, endDay);

  //loops through every line in the input file
  while (fin >> citationNumber >> inputMonth >> inputDay >> inputYear >> clockedSpeed >> speedLimit >> roadType){

    //adds a 0 to the month if the length is one space
    if (to_string(inputMonth).length() == 1){

      inputMonth = stoi("0" + to_string(inputMonth));
    } 

    //adds a 0 to the day if the length is one space
    if (to_string(inputDay).length() == 1){

      inputDay = stoi("0" + to_string(inputDay));
    } 

    //adds a "20" to the year if there's only two digits of the year
    if (to_string(inputYear).length() == 2){
      
      inputYear = stoi("20" + to_string(inputYear));
    }

    //reformats the input date
    serialInputDate = serializeDate(inputYear, inputMonth, inputDay);

    //checks to see if each ticket from input file is between inputted dates
    if ( serialInputDate >= startDate && serialInputDate <= endDate){

      //calculates standard fine
      initialFine = clockedSpeed - speedLimit;

      //adds a "20" to the year if there's only two digits of the year
      /*if (to_string(inputYear).length() == 2){

        inputYear = stoi( "20" + to_string(inputYear));
      }*/

      // using a switch statement to switch between different multiplies based on characters
      switch (roadType) {
        case 'i': case 'I':
          finalFine = initialFine * INTERSTATE_MULTIPLIER;
          break;

        case 'h': case 'H':
          finalFine = initialFine * HIGHWAY_MULTIPLIER;
          break;

        case 'r':case 'R':
          finalFine = initialFine * RESIDENTIAL_MULTIPLIER;
          break;

        default:
          finalFine = initialFine * DEFAULT_MULTIPLIER;
          break;
      }

      //sets the final fine to 0 if the initial fine is 0.00 or less than 0.00
      if (initialFine <= MINIMUM_FINE){

        finalFine = 0.00;
      }

      //formatting to output file
      fout << setw(2) << setfill('0') << inputDay << "-"; 
      fout << THREE_LETTER_MONTHS[inputMonth - 1] << "-" << inputYear << " ";
      fout << left << setw(10) << setfill(' ') << citationNumber;
      fout << right << " $" << setw(9) << fixed << setprecision(2) << finalFine << endl;

    }
  }

  //closes both the input and output file
  fin.close();
  fout.close();

  return 0;
}
