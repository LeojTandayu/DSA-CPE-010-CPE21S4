#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

 
  ///1. Create a C++ program to swap the two numbers in different variables. 

  int a = 10;
  int b = 20;
  int c;
  c = a;
  a = b;
  b = c;
  
  cout << "1) a = " << a << endl;


  cout<<"---------------------"<<endl;
/*2. Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit. */
  int kelvin;
  
  cout<<"2)Enter your Kelvin Temperature:";
  cin>>kelvin;
  int fahrenheit;
  fahrenheit = 9/5 * (kelvin - 273) + 32;
  cout<< "The converted temperatue is: "<<fahrenheit<<endl;

  
  cout<<"---------------------"<<endl; 
  /*3. Create a C++ program that has a function that will calculate the distance between two points.*/
  int x1, x2, y1, y2; 

  cout<<"3)Enter your first x coordinate:";
  cin>>x1;
  cout<<"Enter your first y coordinate:";
  cin>>y1;
  cout<<"Enter your second x coordinate:";
  cin>>x2;
  cout<<"Enter your second y coordinate:";
  cin>>y2;

  int distance;
  distance = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
  cout<<"The distance is:"<<distance<<endl;
  cout<<"---------------------"<<endl; 


  
}
