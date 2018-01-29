    /* ***********************************************************************
 Author: Aida Nordman
 TN012: lab1, exercise 1
 Program to convert currency from Euro to SEK
 Exchange rate: 1 Euro = 9.54008 SEK
 Input: a quantity of Euro
 Output: a quantity of Euro converted to SEK
************************************************************************ */

#include<iostream>   //cin, cout

using namespace std;

int main()
{
    double money_Euro, money_SEK; //variables declaration
    double exchange_Rate = 9.54008; //was not declared

    //Read input data: how much money in euro
    cout << "Euro: "; //Warning, semiicolon before money_sek
    cin >> money_Euro;

    //Convert from Euro to SEK
    money_SEK = exchange_Rate * money_Euro;

    //Display the result: euro -> SEK
    cout << money_Euro << " Euro is converted to "
         << money_SEK << " SEK." << endl;

    //ADD CODE for  Exercise 1.6 below
    cout << "Sek: ";
    cin >> money_SEK;

    //convert from Sek to Euro
    money_Euro = money_SEK / exchange_Rate;

    //display the result: SEK -> euro
    cout << money_SEK << " kr is converted to "
         << money_Euro << " euro." << endl;

}
