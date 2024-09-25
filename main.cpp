#include <iostream>
#include <queue>
using namespace std;


void display (queue<string>pl)
{
    while(true)    
    {
        if(!pl.empty())
        {
        cout<<pl.front()<<endl;
        pl.pop();
        }
        
        else
        {
            cout<<endl;
            cout<<"Stack is empty"<<endl;
            break;
        }
    }
    
    
}
  
int main()
{
    queue <string>pl;
    cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl;
    cout<<"Push elements into stack:"<<endl;
    
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    display(pl);
    

    return 0;
}