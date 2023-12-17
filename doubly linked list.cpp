#include<iostream>
using namespace std;
struct node
{
    node *pre;
    int info;
    node *next;
};
node *start=nullptr;
node *temp=nullptr;
void insertend(int info)
{
    node *newnode=new node;
    newnode->info=info;
    temp=start;
    newnode->next=nullptr;
    if (temp==nullptr)
    {
         start=newnode;
         temp=start;
    }
    else{
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->pre=temp;
}
}
void insertbeg(int info)
{
    node *newnode=new node;
    newnode->info=info;
    if (start==nullptr)
    {
        newnode->pre=nullptr;
        newnode->next=nullptr;
        start=newnode;
    }
    else{

    newnode->pre=nullptr;
    newnode->next=start;
    start->pre=newnode;
    start=newnode;
    }
}
void deletebeg()
{
    node *temp=start;
    start=start->next;
    free(temp);
    start->pre=nullptr;
}
void display()
{
    node *temp=start;
    while(temp!=nullptr)
    {
        cout<<temp->info;
        temp=temp->next;
    }
}
void deleteend()
{
    node *temp1=start;
    node *temp2=start;
    while(temp1->next!=nullptr)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    free(temp1);
    temp2->next=nullptr;
}
int main()
{
    int x;
    char ch;
    do
    {
        cout<<"Enter";
        cin>>x;
        insertbeg(x);
        cout<<"more?";
        cin>>ch;
    }while(ch=='y');
    display();
    deleteend();
    cout<<endl;
    display();
}
