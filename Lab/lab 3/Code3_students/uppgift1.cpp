#include<iostream>
#include<iomanip>
using namespace std;

int main(){

    int age, nr_tickets, price;
    int total_price = 0;

    const int legal_age = 15;
    const int kid_age = 8;

    cout<<"Welcome to our Football Arena!"<<endl;
    cout<<setw(30)<<setfill('-')<<"-"<<endl;

        do{
            cout<<"Number of tickets: ";
            cin>>nr_tickets;

            if(nr_tickets <= 0){
            cout<<"invalid number of tickets!!"<<endl<<endl;
            }

        }while(nr_tickets <= 0);

        for(int i = 0; i<nr_tickets; i++){
            cout<<"Enter age: ";
            cin>>age;

            if(age<kid_age){
                price = 0;
            }else if(age<legal_age){
                price = 30;
            }else{
                price = 80;
            }

            total_price = total_price + price; //price += price; fel ty vid varje loop får price ett nytt värde igen som den adderar mig sig sälv bara
        }

    cout<<"Total price = "<<total_price<< " SEK"<<endl;


return 0;
}
