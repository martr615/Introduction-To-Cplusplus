/**************************************************************************
 Course: TND012, lab6
 Author: Aida Nordman
************************************************************************* */
#include <iostream>
#include <fstream>

#include "movies.h"

using namespace std;

const int SIZE = 100;

/****************************************/
//Function declarations (prototypes)
/****************************************/

// NO CHANGES TO FUNCTION DECLARATIONS ALLOWED HERE!

//Sort alphabetically array V with n movies
//movies name is used for sorting
void sort_movies(Movie V[], int n);


//Read a text file f of movies and
//Load the movies into array V
//Function returns the number of movies read
//Array V has n movie slots
int read_From_File(ifstream& f, Movie V[], int n);


//Write all movies in array V to file f
//Array V stores n movies
void write_to_File(ofstream& f, const Movie V[], int n);


//Display all movies in array V to cout
//Array V stores n movies
void display_db(const Movie V[], int n);


// ADD ADDITIONAL FUNCTIONS BELOW IF NEEDED


/****************************************/
// Main program
/****************************************/

//DO NOT CHANGE THE main() function
int main()
{
    ifstream in_file("movies.txt"); //file to read
    ofstream out_file("movies_sorted.txt"); //file to write

    Movie db[SIZE]; //A database of movies

    //Test if opening the files succeeded
    if ( !in_file || !out_file )
    {
        cout << "Error in file opening" << endl;
        return 1; // end the program
    }

    //Load a file of movies into array db
    int howMany = read_From_File(in_file, db, SIZE);

    if (!howMany)
    {
        cout << "File is empty!!" << endl;
        return 2;
    }

    //Sort array db by movies name
    sort_movies(db, howMany);

    //Display the sorted movies in array db to the screen
    display_db(db, howMany);

    //Save the sorted movies stored in db to a text file
    write_to_File(out_file, db, howMany);

    //close the files
    in_file.close();
    out_file.close();

    return 0;
}

/****************************************/
//Function definitions
/****************************************/

//Sort alphabetically array V with n movies
//movies name is used for sorting
void sort_movies(Movie V[], int n)
{
    //ADD CODE
}


//Read a text file f of movies and
//Load the movies into array V
//Function returns the number of movies read
//Array V has n movie slots
int read_From_File(ifstream& f, Movie V[], int n)
{
    //ADD CODE

    return 0; //delete this
}


//Write all movies in array V to file f
//Array V stores n movies
void write_to_File(ofstream& f, const Movie V[], int n)
{
    //ADD CODE
}



//Display all movies in array V to cout
//Array V stores n movies
void display_db(const Movie V[], int n)
{
     //ADD CODE
}
