/**************************************************************************
 Course: tnd012, lab5
 Authors:
************************************************************************* */

/*Test data 1
country X: 50 50 100 250 100 50 100 85 100 180 10 100 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
*/


/*Test data 2
country X: 50 50 100 250 100 50 100 85 100 180 10 100 50 50 120 120 50 77 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 65 60 190 147 90 90 -1
*/

/*Test data 3
country X: 50 50 100 250 100 50 -1
Sweden:    70 78 170 250 105 90 120 96 160 250 18 150 -1
*/

#include <iostream>
#include <string>

using namespace std;


/*****************************
* Function declarations      *
******************************/

//read a seq of non-negative integer
//into an array and returns the nr
//of values read.
int read_seq(int V[], const int n);

//compare the seq between 2 arrays and
//compute the difference and store it in
//a new array.
void difference(int V1[], int V2[], int V3[], int n);

//a given integer is given. The nr of
//the given integer will return '*'
//where 1 '** corresponds to value 10
void count_stars(int V[], int round[] ,int n);

//Display the first letter of a month
//followed by '*' which corresponds to
//the value returned from count_stars
void display_graph_line(int V[], int disp_stars[] ,int n);

//return the highest value in an array
void max_value(int diff[],  int n);

//return the lowest value in an array
void min_value(int diff[], int n);

/******************************
* MAIN                        *
******************************/
//NOTE: main function body should contain no loops

int main()
{
    //DECLARE THE NEEDED CONSTANTS and VARIABLES HERE
    const int max_month = 240;
    int country_x[max_month] = {0};
    int country_sweden[max_month] = {0};
    int diff_sales[max_month] = {0};
    int show_stars[max_month] = {0};
    int nr_months_x, nr_months_sweden;

    cout << "Enter data for country X: " << endl;
    //1. Read the data for country X
    //ADD CODE: function read_seq can be useful here
    nr_months_x = read_seq(country_x, max_month);


    cout << "\nEnter data for Sweden: " << endl;
    //2. Read data for Sweden
    //ADD CODE:  function read_seq can be useful here
    nr_months_sweden = read_seq(country_sweden, max_month);

    //close the program if the input is wrong
    if(nr_months_x != nr_months_sweden){
        cout<<"\nError input!!"<<endl;
        return 0;
    }

    //3. Calculate the difference between country_X and Sweden
    //ADD CODE:  function difference can be useful here
    difference(country_x, country_sweden, diff_sales, nr_months_x);


    //4. Display the histogram graph
    cout << endl << "The Graph" << endl << endl;
    //ADD CODE: you decide which functions are useful here, if any
    //count_stars(diff_sales, show_stars , nr_months_x); => no need to call here since we can call in the function display instead
    display_graph_line(diff_sales, show_stars , nr_months_x);

    //5. Display the months in Sweden that differ least/most from country_X
    //ADD CODE: functions max_value and min_value can be useful here
    min_value(show_stars, nr_months_x);
    max_value(show_stars,nr_months_x);

    return 0;
}

/*************************************
* Function definitions               *
**************************************/

int read_seq(int V[], const int n){

    const int STOP = -1;
    int nr_downloads;
    int howMany = 0;

    //Bättre med for-loop än den while-loop jag gjorde där nere
    //ty det gå enkelt att säga att inte spara värdet -1 när man
    //avslutar programmet.
    for(int i = 0; i<n; i++){

        cin>>nr_downloads;

        if(nr_downloads <= STOP){
            break;
        }else{
            V[i] = nr_downloads;
            howMany++;
        }
    }

    return howMany;

/*
    do{

        cin>>nr_downloads;
        V[howMany] = nr_downloads;
        howMany++;

    }while(nr_downloads > STOP);
*/
}

void difference(int V1[], int V2[], int V3[], int n){ //country_x, country_sweden, diff_sales, max_month

    for(int i = 0; i< n; i++){

        V3[i] = V2[i] - V1[i];
    }

    /*
    //debug
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<"The difference is V["<<i<<"] = " << V3[i]<<endl;
    }
    */
}

//a given integer is given. The nr of
//the given integer will return '*'
//where 1 '** corresponds to value 10
void count_stars(int V[], int round[], int n){

    //V[] är de värden jag får
    //efter att datorn har beräknat difference
    //n är hur många värde det finns inne i arrayn
    int rest;

    for(int i = 0; i<n; i++){
        rest = V[i] % 10; //if V[i] = 47 then rest is 7
                          //if V[i] = 43 then rest is 3

        if(rest >= 5 && rest != 0){
            round[i] = V[i] - rest;
            round[i] += 10;
        }else if(rest<5 && rest!= 0){
            round[i] = V[i] - rest;
        }else{ //happens when rest = 0
            round[i] = V[i];
        }
    }

    //få de till tiotal dvs om 40 in diff => 4 för att det ska visa '****' och inte 40
    for(int i = 0; i<n; i++){
        round[i] /= 10;
    }


}


void display_graph_line(int V[], int disp_stars[], int n){

    const string months[] = {
                                "J" , "F",
                                "M" , "A",
                                "M" , "J",
                                "J" , "A",
                                "S" , "O",
                                "N" , "D"
                            };

    count_stars(V, disp_stars, n);


    for(int i = 0; i<n; i++){

                      //just nu funkar bara till 24 månader
        if(i >= 12){ //det är nånting med modulus för att få helt rätt
            cout<< months[i-12]<<" ";
        }else{
            cout<< months[i]<< " ";
        }


        for(int j = 0; j<disp_stars[i]; j++){
            cout<<"*";
        }
        cout<<endl;

        if((i+1) % 6 == 0){ // om i = 5 dvs 0,1,2,3,4,5 (sjätte gången) varav +1 och modulus, rest = 0
            cout<<endl;
        }

    }

}


void min_value(int diff[],  int n){ //diff_sales (round), nr_months_x

    //display_graph_line(V, diff, n);

    const string months[] = {
                                "January" , "February",
                                "March" , "April",
                                "May" , "June",
                                "July" , "August",
                                "September" , "October",
                                "November" , "December"
                            };



    int counter = 0;
    int _position[240];
    int _min = diff[0];

    for(int i = 0; i<n-1; i++){       // 60 70 80 90 20 100 120 20 120

        if(diff[i+1] < _min){
            _min = diff[i+1];
        }
    }


    //jag vill inte spara värdena, jag vill spara positionen
    for(int i = 0; i<n; i++){
        if(_min == diff[i]){
            if(i >= 12){
                _position[counter] = i-12;
                counter++;
            }else{
                _position[counter] = i;
                counter++;
            }
        }
    }

    //showcase right number of _max
    _min *= 10;

    cout<<endl<<"Month(s) deviating least from country X: "<<endl;
    for(int i = 0; i<counter; i++){

        int idx = _position[i];

        if(i == counter-1){
            cout<<months[idx]<< "    "<<_min;
         }else{
            cout<<months[idx] << ", ";
        }

    }

}


void max_value(int diff[],  int n){ //diff_sales (round), nr_months_x

    //display_graph_line(V, diff, n);

    const string months[] = {
                                "January" , "February",
                                "March" , "April",
                                "May" , "June",
                                "July" , "August",
                                "September" , "October",
                                "November" , "December"
                            };



    int counter = 0;
    int _position[240];
    int _max = diff[0];

    for(int i = 0; i<n-1; i++){       // 60 70 80 90 20 100 120 20 120

        if(diff[i+1] > _max){
            _max = diff[i+1];
        }
    }


    //jag vill inte spara värdena, jag vill spara positionen
    for(int i = 0; i<n; i++){
        if(_max == diff[i]){
            if(i>= 12){
                _position[counter] = i-12;
                counter++;
            }else{
                _position[counter] = i;
                counter++;
            }
        }
    }

    //showcase right number of _max
    _max *= 10;

    cout<<endl<<"Month(s) deviating most from country X: "<<endl;
    for(int i = 0; i<counter; i++){

        int idx = _position[i];

        if(i == counter-1){
            cout<<months[idx]<< "    "<<_max;
         }else{
            cout<<months[idx] << ", ";
        }

    }

    cout<<endl;
}

