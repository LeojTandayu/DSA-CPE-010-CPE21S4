#include <iostream>
using namespace std;

int main()
{
///initiate the size
    
    int array[] = {10, 7 , 6 , 5 , 9 , 18 , 4 , 3 , 2 , 1};
    
 ///count the length of the array
    cout<<"The length of the array is : "<<sizeof(array) /sizeof(array[0]) <<endl;
    
    
    return 0;
}
