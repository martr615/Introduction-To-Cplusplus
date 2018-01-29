//martr615
//uppgift 4 lab 3

using namespace std;
#include<iostream>

int main(){

    //declare variables
    const int SIZE = 10;
    //array som håller strings och som är 10 stor och innehåller tal från 0-9
    int numbers[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //numbers[0] = 0, numbers[1] = 1 ...

    int letter_D;

    //Varje värde i arrayn ska tilldelas till each letter
    //Display which value represent TOO and by GOOD
    for(int i = 0; i<SIZE; i++){

            for(int j = 0; j<SIZE; j++){
                if(numbers[i] == numbers[j]){ //om numbers[i] = 0 och  numbers[j] = 0 fortsätt nästa iterationen av loop och sätt numbers[j] = 1
                    continue;
                }

                for(int k = 0; k<SIZE; k++){
                    if(numbers[i] == numbers[k] || numbers[j] == numbers[k]){
                        continue;
                    }

                        for(int l = 0; l<SIZE; l++){
                            if(numbers[i] == numbers[l] || numbers[j] == numbers[l] || numbers[k] == numbers[l]){
                                continue;
                            }

/*
                            cout<<"D = "<< numbers[i]<<" "
                                <<"G = "<< numbers[j]<<" "
                                <<"O = "<< numbers[k]<<" "
                                <<"T = "<< numbers[l]<<endl;
                                */

                                //Calculating the words
                    TOO = T * 100 + O * 10 + O;
                    GOOD = G * 1000 + O * 100 + O * 10 + D;

                    // Making a statement that two different letters can't represent the same digit
                    if(GOOD == TOO + TOO + TOO + TOO && T != O && T != G && T != D && O != G && O != D && G != D)
                    {
                        //output data
                        cout << "TOO = " << TOO << " " << "GOOD = " << GOOD << endl;
                    }


                        }

                }
            }

    }


    return 0;
}
