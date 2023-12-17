#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
node *top=nullptr;
void push(int info)
{
    node *newnode=new node;
    newnode->info=info;
    newnode->next=top;
    top=newnode;
}
void display()
{
    node *temp=top;
    while(temp!=nullptr)
    {
     cout<<temp->info;
     temp=temp->next;
    }
}
void pop()
{
    node *temp=top;
    if (top==nullptr)
    {
        cout<<"stack overflow";
    }
    else{
    top=top->next;
    free(temp);
    }
}
int main()
{
    int x;
    char ch;
    do
    {
    cout<<"Enter the value you want to push";
    cin>>x;
    cout<<"more?";
    cin>>ch;
    }while(ch=='y');
    push(x);
    display();
    pop();
    display();
}
