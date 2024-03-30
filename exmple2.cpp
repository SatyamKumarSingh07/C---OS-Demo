#include<iostream>
using namespace std;
struct Node
{
int nodedata;
struct Node  *next;
}
*header;
int header;
void createlist(int n){
    struct Node *newnode , *temp;
    int data ,i;

    if (newnode==NULL)
    {
        cout<<"cant locate a linked list";

    }
    else {
        cout<<"how many nodes you want to create";
        cin>>i;
        cout<<"Enter the data of the nodes";
        cin>>data;
        newnode->nodedata = data;
        newnode->next=NULL;
        header=newnode;


    }
    for (int j=2;j<=n; j++){


    }



    }
    int main(){

    };

    



}
}
