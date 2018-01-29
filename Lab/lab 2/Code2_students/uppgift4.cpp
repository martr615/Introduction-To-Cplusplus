#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){

    //declare variables
    const double DELTA = 10e-10;
    double b, c, x1, x2, check_inside_root;


    //input and message
    cout<<"Solving a second degree equation"<<endl;
    cout<<"of the form x^2 + b*x + c"<<endl<<endl;
    cout<<"Enter coefficient b: ";
    cin>>b;
    cout<<"Enter coefficient c: ";
    cin>>c;

    //calculate second degree eq
    check_inside_root = ((b/2)*(b/2) -c);
    x1 = -(b/2) + sqrt(check_inside_root); //calculate x1
    x2 = -(b/2) - sqrt(check_inside_root); //calculate x1


   //output has 3 digits of decimal
    cout<<fixed<<setprecision(3);

    //output for complex roots
    if(check_inside_root < 0){
        cout<<"x1 and x2 are complex roots!!"<<endl;
    }else if(fabs(x1 - x2) < DELTA || fabs(x2 - x1) < DELTA){ //HUR MAN JÄMFÖR EN DOUBLE
        //double root
        cout<<"x1, x2 = "<< x1 << "     (double root)"<<endl;
    }else{
        //output for 2 real roots
        cout<<"x1 = "<<x1<<endl;
        cout<<"x2 = "<<x2<<endl;
    }



return 0;
}
