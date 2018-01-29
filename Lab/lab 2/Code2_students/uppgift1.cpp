/*
* TND012, Lab2: exercise 1
*
* Answer the following questions:
* 1 - What output would you expect from the program?     -> sum1 is 1.0
* 2 - What is the output obtained when you run the program?     -> sum1 is different from 1.0
* 3 - If the expected output differs from the actual output produced
*     by the program, then investigate a possible explanation for this behaviour.   -> it is because a double should be compared differently (fabs)
* 4 - Check whether the compiler produced any warning message
*     after compilation and write it down.      ->comparing floating point with == or != is unsafe
*/

#include <iostream>

using namespace std;

int main()
{
    double sum1;

    sum1 = 0.5 + 0.2 + 0.1 + 0.1 + 0.1;

    if( sum1 != 1.0 )
        cout << "sum1 is different from 1.0 !!" << endl;
    else
        cout << "sum1 is 1.0 ." << endl;
}
