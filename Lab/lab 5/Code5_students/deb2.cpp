//
// Course: TND012, lab 5
//   Debugging Functions
//
// Author: Martin Falk
//

#include <cstdlib> // rand()
#include <iostream>

using namespace std;

long long int factorial(int n)
{
    long long int product = 1;

    for (int i = 2; i < n; ++i)
    {
        product *= i;
    }

    return product;
}

int main()
{
    const int numSamples = 10;

    int k = numSamples;

    while (k > 0)
    {
        int v = rand() % 20;

        long long int result = factorial(v);

        cout << "factorial(" << v << ") = " << result << endl;

        --k;
    }
}
