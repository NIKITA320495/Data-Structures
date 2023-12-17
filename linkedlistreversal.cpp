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
    newnode->next=nullptr;
    newnode->info=info;
    newnode->next=start;
    start=newnode;
}
void display()
{
    node *temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->info<<"<";
        temp=temp->next;
    }
}
node *curr;
node *prev=nullptr;
node *nextptr;
void reversal()
{
    curr=start;
    while(curr!=nullptr)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
}
int main()
{
    create(5);
    create(6);
    create(7);
    create(9);
    display();
    reversal()
    display();
}
