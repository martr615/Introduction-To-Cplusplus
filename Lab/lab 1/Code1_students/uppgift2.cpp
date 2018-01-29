/*
Author: Martin Tran
TN012: lab1, exercise 2
Program to display the use amount of electricity
Input:
Output:
*/

#include <iostream>
using namespace std;

int main(){

//declare variables
int elec_Now, elec_Then, elec_Used;

cout << "Enter electricity meter reading a year ago: "; //ask for electricity used a year ago
cin >> elec_Then; //input
cout << "Enter electricity meter reading now: "; //ask for electricity used this year
cin >> elec_Now; //input

//calculate the electricity used in a year
elec_Used =  elec_Now - elec_Then;

//display the result
cout << "You have used " << elec_Used << " kWh during the last year." << endl;

}
