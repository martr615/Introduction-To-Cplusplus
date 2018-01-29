#include <cstdlib> //rand
#include <iostream>

using namespace std;

int main()
{
  int n = 0;

  n = 10;
  int sum = 0;

  while (n > 0)
  {
    sum += n;
    --n;
  }

  cout << "The sum is: " << sum << endl;

  // compute average
  //cout << "Average: " << sum / n << endl;
}
