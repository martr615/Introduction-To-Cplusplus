/*
Author: Martin Tran
TN012: lab1, exercise 3
Program to display the use amount of electricity
Input:
Output:
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

//declare variables
int elec_Now, elec_Then, elec_Used;
double elec_Cost, total_Cost, normal_Cost, extra_Cost;

cout << "Enter electricity meter reading a year ago: "; //ask for electricity used a year ago
cin >> elec_Then; //input
cout << "Enter electricity meter reading now: "; //ask for electricity used this year
cin >> elec_Now; //input
cout << "Enter regular price of 1kWh: ";
cin >> elec_Cost;

//calculate the electricity used in a year
elec_Used =  elec_Now - elec_Then;
extra_Cost = elec_Used*0.1*elec_Cost*1.05;
normal_Cost = elec_Used*0.9*elec_Cost;
total_Cost = normal_Cost + extra_Cost;

//display the result
cout << endl;
cout << "You have used " << elec_Used << " kWh during the last year." << endl;
cout << "Total cost = " << fixed << setprecision(2) <<total_Cost << " kr" << endl;
cout << "10% of the used energy costs " << extra_Cost << " SEK" << endl;
}
