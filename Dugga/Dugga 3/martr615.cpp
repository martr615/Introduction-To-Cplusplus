// ================================================================
// Author: Martin Tran, 930201-5616
// TND012: Dugga 3, 2017-10-06/2017-10-08
// Input: Positive integers that represent product codes
// Output: A table that show valid codes and invalid codes
// ================================================================


using namespace std;
#include<iostream>
#include<iomanip> //setw, setfill

//Calculate the size of a given input
int input_length(long long int code);

//send in a digit for every second number
//that calcEven() does not get from a given input
int calcODD(int digit);

//send in a digit for every second number with start from the right
int calcEVEN(int digit);

//read user input
//store the inputs in an array
int read_codes(long long int codes[], int n);

//Test if the given code is valid
//pass by reference for a and b because these values
//are changed in check_code() that will be passed on to display_table()
void check_code(long long int codes[], long long int valid[], long long int invalid[], int n, int& a, int& b);

//display 2 column table
//table 1: valid codes
//table 2: invalid codes
void display_table(long long int codes[], long long int valid_codes[], long long int invalid_codes[], int n, int& a, int& b);


int main(){

    const int SIZE = 100; //reasonable size for the array (no more than 100 inputs)
    long long int vault[SIZE] = {0}; //Store the given user inputs
    long long int valid_code[SIZE] = {0}; //store valid inputs
    long long int invalid_code[SIZE] = {0}; //store invalid inputs

    int howMany = 0; //calculate how many input the user has given
    int valid_counter = 0;
    int invalid_counter = 0;

    //1. read in a list of product codes
    cout<<"Enter the codes: "<<endl; //asking for product codes

    howMany = read_codes(vault, SIZE); //howMany is the returned value of the function read_codes()

    //2. Display valid and invalid codes in separate columns
    cout<<endl<<endl;
    cout<<setw(20)<<"Valid codes"
        <<setw(30)<<"Invalid codes"<<endl;
    cout<<setw(60)<<setfill('=')<<"="<<endl;

    display_table(vault, valid_code, invalid_code, howMany, valid_counter, invalid_counter);

    return 0;

}

//Calculate the size of a given input
int input_length(long long int code){


    const int nextNR = 10;
    const int STOP = 0;
    int length = 0;


    while(code != STOP){ //stop the loop when the input is equal to 0
        code /= nextNR; //take away the last digit
        length++; //add 1 to length
    }

    return length;

}

//take the digit for every second number that calcEven() does not get
int calcODD(int digit){

    int sum = 0;

    sum = digit;//assign sum to one digit

    return sum;

}

//take the digit for every second number that start from the right
int calcEVEN(int digit){

    const int doubleDigit = 2;
    const int nextNR = 10;
    int sum = 0;
    int res;

    //take the digit and times 2
    digit *= doubleDigit;

    //check the length of the value after doubling the digit
    int lenght = input_length(digit);

    if(lenght == doubleDigit){ //if the value has 2 digits

        //loop trough the 2 digits and separate the value and add them as a sum
        for(int i = 0; i<lenght; i++){
           res = digit % nextNR; //take the last digit
           digit /= nextNR ; //take away the last digit
           sum += res;
        }

    }else{ //if the digit is not a value with 2 digits
        sum = digit;
    }

    return sum;
}

//read user input
//store the inputs in an array
int read_codes(long long int codes[], int n){

    int counter = 0; //check for howMany
    long long int product_code; //User input

    //User decides when the seq should stop by writing e.g "stop"
    //No need to validate the input since we assume that the given
    //input is only positive integers without leading zeros.

    while((cin>>product_code) && (counter<n)){ //loop as long as input is a positive integer and the input has not been given over 100 times

        codes[counter] = product_code; //store codes in the array
        ++counter; //increment of the arrays size

    }

    return counter; //return howMany input is given

}

//Test if the given code is valid
void check_code(long long int codes[], long long int valid[], long long int invalid[], int n, int& a, int& b){

    //eliminate magic numbers
    const int EVEN = 2;
    const int validInput = 10;
    const int nextNR = 10;
    const int lastPlace = 1;

    //declare variables
    int oneDigit;

    //check for all of the given inputs
    for(int i = 0; i<n; i++){

        //declare calculation variables and
        //reset every time we enter a new input
        int result = 0;
        int sum1 = 0;
        int sum2 = 0;
        int digitPlacement = lastPlace; //start with the last digit of a product code

        long long int oneCode = codes[i]; //assign oneCode for the given input
        int length = input_length(oneCode); //send oneCode to function input_length and return the inputs length

        for(int j = 0; j<length; j++){

            oneDigit = codes[i] %nextNR; //take the last digit of the integer for the given input
            codes[i] /= nextNR; //take away the last digit

            //declare calculation variables and reset every time
            //we enter a new digit of the ongoing input
            int oddDigit = 0;
            int evenDigit = 0;

            if(digitPlacement % EVEN == 0){ //for every second digit enter this block
                evenDigit = calcEVEN(oneDigit);
            }else{
                oddDigit = calcODD(oneDigit);
            }


            digitPlacement++; //iterate to enter every second digit every second time

            //add to the result for the given input (one product code at a time)
            sum1 += oddDigit;
            sum2 += evenDigit;
        }

        //sum the result of odd and even
        result = sum1 + sum2;

        //if the result is divisible by 10 then the input is valid
        if(result % validInput == 0){
            valid[a] = oneCode; //store the valid input in the valid array
            a++;
        }else{
            invalid[b] = oneCode; //store the invalid input in the invalid array
            b++;
        }
    }
}

void display_table(long long int codes[], long long int valid_codes[], long long int invalid_codes[], int n, int& a, int& b){

    int _max, _min;

    check_code(codes, valid_codes, invalid_codes, n, a, b);

    //find the highest value between a and b
    if(a<b){
        _max = b;
        _min = a;
    }else{ //happens when a>b or when a = b
        _max = a;
        _min = b;
    }

    cout<<setfill(' ')<<" "<<endl;

    for(int i = 0; i<_min; i++){ //display both of the array until 1 array ends
        cout<<setw(20)<<valid_codes[i]
            <<setw(30)<<invalid_codes[i]<<endl;
    }

    if(_max == a){ //if validate_code is longer then continue displaying validate_code
        for(int i = _min; i<_max; i++){ //start where it ended in the for-loop above
            cout<<setw(20)<<valid_codes[i]<<endl;
        }
    }else{ //if _max = b then invalid_codes are longer than valid_codes and continue displaying invalid_codes
        for(int i = _min; i<_max; i++){
            cout<<setw(50)<<invalid_codes[i]<<endl;
          }
    }

    cout<<endl;

}

