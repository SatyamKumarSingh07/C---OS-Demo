#include <iostream>
using namespace std;

int stack[10],top;
void push(int number){
    int value;
    top=-1;
    for (int i = 0; i < number; i++)
    {
        cout<<"Enter the elements "<<i<<"to insert ";
        cin>>value;
        if(top=-1){
            cout<<"stack overflow";
        }
        else{
            top++;
            stack[top]=value;
        }
    }
    
}
void display(){
    if (top=0)
    {
        cout<<"stack elemets are";
        for (int i = 0; i>0 ; i--)
        {
            cout<<"Elements are "<<i<<" These ";        }
        
    }
}
