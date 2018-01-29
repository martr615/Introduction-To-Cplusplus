//martr615
//uppgift 3 av lab 3

using namespace std;
#include<iostream>
#include<iomanip> //fixed, setprecision

int main(){

    //declare array
    const int MAX = 20;
    double productPrice[MAX]; //array with 20 slots, [0-19]

    //declare outputs
    double tax, price_tax, tax_percentage;

    //eliminating magic numbers
    const double tax_in_kr = 100.0;

    //input: Enter products price (for-loop to access array)
    cout<<"Enter products price: ";

    for(int i = 0; i<MAX; i++){
        cin>>productPrice[i];
    }

    //input: Enter tax
    cout<<"Enter tax: ";
    cin>>tax_percentage;

    //show 2 decimals
    cout<<fixed<<setprecision(2)<<endl;
    //Display output: A table containing of price and taxes
    cout<<"Taxes Table"<<endl;
    cout<<"Tax = " << tax_percentage << "%"<<endl<<endl;

    cout<<"Price tax free"
        <<setw(10)<<"Tax"
        <<setw(20)<<"Price with tax"<<endl;
    cout<<setw(50)<<setfill('-')<<"-"<<endl; //lägger till en rad med ----------
    cout<<setfill(' '); //ta bort "-------" så att det blir "          " igen

    for(int i = 0; i<MAX; i++){
        //calculate tax and price with tax
        tax = productPrice[i]*(tax_percentage/tax_in_kr); //dela med 100 för att få first_price*0.25 och inte first_price*25 om tax_percentage = 25
        price_tax = productPrice[i] + tax;

        cout<<setw(9)<<productPrice[i]
            <<setw(15)<<tax
            <<setw(15)<<price_tax <<endl;

    }

    return 0;
}
