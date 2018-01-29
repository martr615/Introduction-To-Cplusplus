/**************************************************************************
 Author: Aida Nordman
 Course: tnd012, lab4
 Program to find prime numbers
************************************************************************* */

#include <iostream>
#include <iomanip> //setw, setfill

using namespace std;

const int EXIT = 5;

//ADD any needed functions here
bool test_prime(int n);

int next_prime(int n);

int prev_prime(int n);

void display_primes(int n);

int main()
{

    int option = EXIT; // EXIT = 5 (global variabel)

    //declare any other needed variables and constants here
    int test_value;

    do
    {
        //Display the menu
        cout<<setw(20)<<setfill('=')<<"="<<endl
            <<"1. Test prime "<<endl
            <<"2. Next prime "<<endl
            <<"3. Previous prime "<<endl
            <<"4. Display primes "<<endl
            <<"5. Exit "<<endl
            <<setw(20)<<setfill('=')<<"="
            <<setfill(' ')<<" "<<endl<<endl;

            cout<<"Your choice: ";
            cin>>option;

        //Read user option
        switch(option){
            case 1:

                cout<<"Test prime: ";
                cin>>test_value;
                cout<<endl;

                if(test_prime(test_value)){ //test_prime(test_value) == true, för att den är för-definierad som det som standard?
                    cout<<test_value<<" is a prime number"<<endl<<endl;
                }else{
                    cout<<test_value<<" is not a prime number"<<endl<<endl;
                }

                break;

            case 2:

                cout<<"Test prime: ";
                cin>>test_value;
                cout<<endl;

                //next_prime(test_value); //skicka in input dvs test_value
                //behövs inte....verkar som att där nere skickar det värdet
                //samt return funktionen direkt

                cout<<"Next prime of " << test_value
                    <<" is "<<next_prime(test_value)<<endl<<endl; //få svaret dvs return p;

                break;

            case 3:

                cout<<"Test prime: ";
                cin>>test_value;
                cout<<endl;

                //prev_prime(test_value); //skicka in input dvs test_value4
                //behövs inte....verkar som att där nere skickar det värdet
                //samt return funktionen direkt

                cout<<"Previous prime of " << test_value
                    <<" is "<<prev_prime(test_value)<<endl<<endl; //få svaret dvs return p;


                break;

            case 4:

                cout<<"Test prime: ";
                cin>>test_value;
                cout<<endl;

                cout<<"Prime in [1,"<<test_value<<"]"<<endl;
                display_primes(test_value);

                break;

            case 5:
                cout<<"Exiting the program..."<<endl;

                break;

            default:
                cout<<"Wrong option!!"<<endl;
        }

        //Handle user option
    }while (option != EXIT);


    return 0;
}

bool test_prime(int n){

    for(int namnare = 2; namnare < n; namnare++)
    {
        if (n % namnare == 0) //if this happens, n is not a prime number.
        {                    //Prime is not divisible by 0
            return false;
        }
    }
    return true ;
}

int next_prime(int n){

    int p; //the returned value hence next prime
    int nextNr = n+1; //n = test_value. so if test_value = 15 we want to start
                        //with checking 16 and not 15.

    while(!test_prime(nextNr)){ //as long as nextNr is not true (prime number) continue with loop

        nextNr++; //iterate
    }

    p = nextNr; //p is the next prime


    return p;

}

int prev_prime(int n){

    int p;
    int prevNr = n-1;

    while(!test_prime(prevNr)){
        prevNr--;
    }

    p = prevNr;

    return p;
}

void display_primes(int n){

    for(int i = 2; i <= n; i++){

        if(test_prime(i)){
            cout<<i<<" ";
        }
    }

    cout<<endl<<endl;
}

