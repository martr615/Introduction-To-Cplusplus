#include<iostream>
using namespace std;

int main(){

    //declare variables
    int dep_hour, dep_min, dur_hour, dur_min, ari_hour, ari_min,
    temp_hour, temp_min;

    //input data (departure time of the flight)
    cout<<"Enter the departure time of the flight: ";
    cin>>dep_hour>>dep_min;

    //if wrong input show error message and then terminate the program
    //check for error (for example if input is negative hour/minutes)
    if(dep_min<0 || dep_min>60 || dep_hour<0 || dep_hour>23){
        cout<<"Wrong input given!!"<<endl;
    }else{
        //input data (the flight duration)
        cout<<"Enter the flight duration: ";
        cin>>dur_hour>>dur_min;

        //check for wrong input
        if(dur_min<0 || dur_min>60 || dur_hour<0 || dur_hour>23){
        cout<<"Wrong input given!!"<<endl;
        }else{
         //calculate the arrival time
        ari_hour = dep_hour + dur_hour;
        ari_min = dep_min + dur_min;

        //add 1 hour if it is over 60 minute and start over
        if(ari_min>=60){
            ari_hour += 1;
            temp_min = ari_min - 60;
            ari_min = temp_min;
        }

        //if hour is over 24 start over from 0
        if(ari_hour >= 24){
            temp_hour = ari_hour - 24;
            ari_hour = temp_hour;
        }

        //output (arrival time of the flight with the given information)
        if(ari_hour<10 && ari_min<10){
            cout<<"The time of arrival is: (0"<<ari_hour<<":0"<<ari_min<<")"<<endl;
        }else if(ari_hour<10){
            cout<<"The time of arrival is: (0"<<ari_hour<<":"<<ari_min<<")"<<endl;
        }else if(ari_min<10){
            cout<<"The time of arrival is: ("<<ari_hour<<":0"<<ari_min<<")"<<endl;
        }else{
            cout<<"The time of arrival is: ("<<ari_hour<<":"<<ari_min<<")"<<endl;
            }
        }
    }

return 0;
}
