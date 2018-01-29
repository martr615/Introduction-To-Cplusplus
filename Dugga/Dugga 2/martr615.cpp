// ================================================================
// Author: Martin Tran, 930201-5616
// TND012: Dugga 2 V1, 2017-09-22/2017-09-24
// Read in a sequence to store the height of students in an array.
// User decides when the seq should stop by writing a non negative
// integer or by typing something that is not a number e.g "Stop"
// Display a table that shows the number of a students height
// and display average height and the percentage of students in
// the expected height range.
// =================================================================

using namespace std;
#include<iostream>
#include<iomanip> //setw, fixed, setprecision

int main(){

    //declaring variables
    const int MAX = 100; //deciding a reasonable number for students in a small school
    const int STOP = 0;

    int student[MAX] = {0}; //the size must be known during compilation, the array is 100 big [0 - 99] where each slot store 0
    int howMany = 0; //counts how many values are stored in the seq.
    int height; //input given by the user


    /**********************************************************
    * 1. Read heights for students in a sequence.             *
    *    Note: Since "the user only enters positive integers" *
    *    I count negative integers as "non-numeric value"     *
    ***********************************************************/

    //INPUT: Asking for students height
    cout<<"Enter the height of each students: ";

    //read in all the given inputs for X students
    while((cin>>height) && (height>=STOP) && (howMany<MAX)){ //loop as long as height is a positive integer and input has not been given over 100 times

        student[howMany] = height; //store value in the array
        ++howMany; //increment of sequence's size

    }

    //if the first input is not valid, close the program
    if(howMany == STOP){
        cout<<"No input given!!!"<<endl;
        return 0;
    }


    /**************************************************************
    * 2. loop the seq to find same (heights) and then add if found*
    ***************************************************************/


    //declare a new array to store unique numbers
    int uniqHeight[MAX] = {0}; //same size as the previous array because uniqHeight will never be bigger
    //declare another array to count for each input how many times they are being repeated
    int counter[MAX] = {0};

    for(int i = 0; i<howMany; i++){
        counter[i] = 1; //every slot in the array has value 1 because every given number have at least come up once obviously
        uniqHeight[i] = student[i]; //copy all students heights
    }

    //loop and compare all of the input with each other once
    for(int i = 0; i < howMany-1; i++){ //howMany-1 because we want to be inside the array since next line has int j = i+1;.
        for(int j = i+1; j<howMany; j++ ){ //we dont need to compare student[0] with student[0]

            if(student[i] == student[j]){ //if same value
                counter[i]++; //add 1
                uniqHeight[j] = 0; //if repeated height, set the repeated as 0
            }

        }
    }
    /**************************************************************
    * 3. calculate the average height of the given input          *
    * 4. calculate the percentage of the expected height range    *
    ***************************************************************/

    //declaring calculation
    double average_h = 0;
    double height_range = 0;

    //eliminate magic numbers
    const int average_low = 165;
    const int average_high = 175;
    const int percentage = 100;

    //loop through the given inputs
    for(int i = 0; i<howMany; i++){

        average_h += student[i]; //add ALL given inputs and sum it up.

        if(student[i]>=average_low && student[i]<= average_high){ //if given input is inside height range [165-175]
            height_range++; //count height_range as 1 person
        }

    }

    average_h /= howMany;
    height_range = (height_range*percentage)/howMany;


    /**************************************************************
    * 5. Display a table that shows the number of students height *
    ***************************************************************/

    //Display "header"
    cout<<endl<<"Height"
        <<setw(25)<<"Number of students"<<endl;
    cout<<setw(30)<<setfill('-')<<"-"<<endl;
    cout<<setfill(' ');

     //loop through all the given input and display
    for(int i = 0; i < howMany; i++){
        if(uniqHeight[i] != 0){ //if not repeated height
            cout<<student[i]   //display height
                <<setw(20)<<counter[i]<<endl; //Display number of times.
                                              //Dont need to be more precise with
                                              //setw and setfill since input is always 3 digits
        }
    }


    /**************************************************************
    * 6. Display average height and the percentage of the expected*
    *    height                                                   *
    ***************************************************************/

    cout<<endl<<fixed<<setprecision(2)
        <<"Average height = " << average_h << " cm"<<endl;
    cout<<"Percentage of students in the expected height range (165-175): "<<height_range<<endl;

    return 0;
}
