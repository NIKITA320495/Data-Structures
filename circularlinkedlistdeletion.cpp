#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
node *start=nullptr;
void create(int info)
{
    node *newnode=new node;
    newnode->info=info;
    newnode->next=nullptr;
    node *temp=start;
    if (start==nullptr)
    {
        newnode->next=newnode;
        start=newnode;
    }
    else{
    while(temp->next!=start)
       {
           temp=temp->next;

       }
       temp->next=newnode;
       newnode->next=start;
       start=newnode;
}
}
node *temp=nullptr;
node*temp1=nullptr;
void delfrombeg()
{
    temp=start;
    temp1=start;
     while(temp1->next!=start)
       {
           temp1=temp1->next;

       }
    start=start->next;
    temp1->next=start;
    free(temp);
}
void delfromend()
{
    node *temp1=start;
    node *temp2=start;
    while(temp1->next!=start)
       {
            temp2=temp1;
           temp1=temp1->next;


       }
       temp2->next=start;
       free(temp1);
}
void display()
{
    node *temp1=start;
    do
    {
        cout<<temp1->info<<"<";
        temp1=temp1->next;
    } while(temp1!=start);
}
int main()
{
    int x;
     char ch;
    do
    {
        cout<<"enter the values";
        cin>>x;
        create(x);
        cout<<" do you want more";
        cin>>ch;
    }while(ch=='y');
    delfromend ();
    display();

}

