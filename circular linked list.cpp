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
void insertend(int info)
{
    node *newnode=new node;
    newnode->info=info;
    newnode->next=nullptr;
    node*temp=start;
     if (temp==nullptr)
    {
         start=newnode;
         newnode->next=newnode;
         temp=start;
    }
    else{
    while(temp->next!=start)
       {
           temp=temp->next;

       }
    temp->next=newnode;
    newnode->next=start;

    }
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
        insertend(x);
        cout<<" do you want more";
        cin>>ch;
    }while(ch=='y');
    display();

}


