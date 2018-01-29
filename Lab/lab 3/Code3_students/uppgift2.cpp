//martr615
//uppgift 2 av lab 3

using namespace std;
#include<iostream>
#include<cmath>
#include<iomanip> //setfill, setw, fixed, setprecision


int main(){

    //declare variables
    double first_price, last_price, step, tax_percentage; //declaring input
    double tax, price_tax; //declaring output
    const double DELTA = 10e-10; //declaring "compare with double", delta <= 0
    const double ZERO = 0.0;
    const double tax_in_kr= 100.0; //eliminating magic numbers

    bool invalid_input = true; //declaring a boolean

    do{
        //Enter input: First price
        cout<<"Enter first price: ";
        cin>>first_price;
        //Enter input: Last price
        cout<<"Enter last price: ";
        cin>>last_price;
        //Enter input: Price step
        cout<<"Enter price step: ";
        cin>>step;
        //Enter input: Tax percentage
        cout<<"Enter tax percentage: ";
        cin>>tax_percentage;

        //check for user input errors and display error message. Re-enter the data
        //first price or last price or step or tax cant be negative ---->>> FUNKAR INTE �N, VET EJ VARF�R VILL TEX ATT DE SKA KUNNA BLI NOLL
        //first price cant be larger than last price. //FUNKAR
        //price step cant be zero // FUNKAR
        invalid_input = (first_price<ZERO || //first_price f�r inte vara noll eller mindre
                         last_price<ZERO  || //last_price f�r inte vara noll eller mindre
                         tax_percentage<ZERO || //tax_precentage f�r inte vara noll eller mindre
                         last_price<first_price ||  //first_price f�r inte vara st�rre �n last_price
                         step<DELTA); //step f�r inte vara 0 eller mindre

        if(invalid_input){
            cout<<"Wrong input!! Please enter again"<<endl;
        }

        cout<<endl;

    }while(invalid_input);

    //show 2 decimals
    cout<<fixed<<setprecision(2)<<endl;
    //Display output: A table containing of price and taxes
    cout<<"Taxes Table"<<endl;
    cout<<"Tax = " << tax_percentage << "%"<<endl<<endl;
    cout<<"Price tax free"
        <<setw(5)<<setfill(' ')<<" "<<"Tax"
        <<setw(10)<<setfill(' ')<<" "<<"Price with tax"<<endl;
    cout<<setw(50)<<setfill('-')<< "-"<<endl;


    //loop from first price to second price with price step to calculate the price with tax
    while(first_price <= last_price){

        //calculate tax and price with tax
        tax = first_price*(tax_percentage/tax_in_kr); //dela med 100 f�r att f� first_price*0.25 och inte first_price*25 om tax_percentage = 25
        price_tax = first_price + tax;

        cout<<first_price
            <<setw(15)<<setfill(' ')<<" "<<tax
            <<setw(10)<<setfill(' ')<<" "<<price_tax <<endl;

        first_price += step;
    }


    //anv�nder for-loop ist�llet f�r while-loop....B�da funkar
/*
    //loop from first price to second price with price step to calculate the price with tax
    for(double i = first_price; i<=last_price; i+=step){
        //calculate tax and price with tax
        tax = first_price*(tax_percentage/tax_in_kr); //dela med 100 f�r att f� first_price*0.25 och inte first_price*25 om tax_percentage = 25
        price_tax = first_price + tax;
        first_price +=step;

        cout<<i
            <<setw(15)<<setfill(' ')<<" "<<tax
            <<setw(10)<<setfill(' ')<<" "<<price_tax <<endl;

    }
*/




    return 0;
}
