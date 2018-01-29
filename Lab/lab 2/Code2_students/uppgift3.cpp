#include<iostream>
#include<iomanip>
using namespace std;

int main(){

int age;
int legal_age = 15;
int kid_age = 8;

cout<<"Welcome to our Football Arena!"<<endl;
cout<<setw(30)<<setfill('-')<<"-"<<endl;
cout<<"Enter age: ";
cin>>age;

if(age<kid_age){
    cout<<"Price = It's free!"<<endl<<endl;
}else if(age<legal_age){
    cout<<"Price = 30 SEK"<<endl<<endl;
}else{
    cout<<"Price = 80 SEK"<<endl<<endl;
}


return 0;
}
