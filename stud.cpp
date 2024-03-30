#include<iostream>
#include <stdlib.h>
using namespace std;
struct stud
{
  int roll;
char name [30];
int age;
struct stud *next;

};

int main(){
  struct stud n1,n2,n3;
  struct stud *p;
 cout<<"Enter roll no"<<endl;
 cin>>n1.roll;
 cout<<"Name"<<endl;
 cin>>n1.name;
 cout<<"age";
 cin>>n1.age;
 n1.next = NULL;
    //n2.next =&n3;
    //n3.next = NULL;
    p=&n1;

    while (p!=NULL)
    {
      cout<<n1.roll<<" " <<n1.name<<" " <<n1.age;
      p=p->next;
    }
    

}