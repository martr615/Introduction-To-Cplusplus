/**************************************************************************
 Course: TND012, lab6
 Author: Aida Nordman
************************************************************************* */
#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


// DO NOT CHANGE THE GIVEN FUNCTION DECLARATIONS
// DO NOT ADD NEW FUNCTIONS

using namespace std;

// ADD NEW DATA TYPE "Movie" HERE



//Read the data for a movie (name, number of copies, type) from file in
//and store the data in the parameter m
void get(ifstream &in, Movie& m);


//Write the data of movie m to file ut
void put(ofstream &ut, const Movie& m);


//Write the data of movie m to cout
void put(const Movie& m);


//Return true, if m1's name is alphabetically larger than m2's name
//Otherwise, returns false
bool larger_than(const Movie& m1,const Movie& m2);


#endif // MOVIES_H_INCLUDED
