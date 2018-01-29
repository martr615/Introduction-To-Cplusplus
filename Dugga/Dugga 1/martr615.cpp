// ================================================================
// Author: Martin Tran, 930201-5616
// TND012: Dugga 1, 2017-09-08/2017-09-10
// Input: Km driven for the rented car
// Output: The price for renting the car calculated by the km driven
// =================================================================

using namespace std;
#include<iostream>
#include<cmath> //modulus (%)
#include<iomanip> //setfill, setw

int main(){

    //Declare variables
    int start_km, end_km; //declaring input
    int rental_cost = 0; //declaring output
    int rest, km_driven, round_mile, extra_cost; //declaring calculations

    //eliminating magic numbers
    const int extra_mile = 5;
    const int high_price = 200;
    const int low_price = 125;

    //Check for input error
    //if wrong input => error message
    //and enter input again
    bool invalid_kms = true; //declaring a boolean

    do{ //do the operation at least once.

        //Input: Driven km by the car before renting
        cout<<"Starting Kms? ";
        cin>>start_km;

        //Input: Driven km after renting the car
        cout<<"Ending Kms? ";
        cin>>end_km;

        //check error condition
        invalid_kms = (start_km < 0 || end_km < start_km);

            //error message
            if(invalid_kms){
                cout<<"Wrong input!!"<<endl<<endl;
            }

    }while(invalid_kms); //if invalid_kms is true, run again.

    //if correct input => calculate the price for renting the car
    km_driven = end_km - start_km;
    rest = km_driven % 10; //check for rest, for example: 47%10 = 7

        if(rest < 10 && rest != 0){
            round_mile = (km_driven - rest)/10;
            round_mile++; //round up
        }else{ //happens when rest == 0
            round_mile = km_driven/10;
        }

        //Om man åker 52 km måste man betala 5*125 kr + 1*200 kr.
        if(round_mile > extra_mile){ //if you have driven more than 50kms
            extra_cost = (round_mile - extra_mile)*high_price; //extra price for the kms over 50kms driven
            rental_cost =  extra_mile*low_price + extra_cost; //total cost where the first 50kms are cheaper
        }else{
            rental_cost = round_mile*low_price;
        }

    //display the result
    cout<<setw(30)<<setfill('-')<< "-" <<endl;
    cout<<"Kms driven = " <<km_driven<<endl;
    cout<<"miles (round up) = " <<round_mile<<endl;
    cout<<setw(30)<<setfill('-')<< "-" <<endl;

    //display the price
    cout<<"Price = "<<rental_cost<<" sek" <<endl;


    return 0;
}
