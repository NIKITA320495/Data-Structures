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
    node *temp;
    node *newnode= new node;
    newnode->info=info;
    temp=start;
    newnode->next=nullptr;
    if (temp==nullptr)
    {
         start=newnode;
         temp=start;
    }
    else
    {
       while(temp->next!=nullptr)
       {
           temp=temp->next;

       }
       temp->next=newnode;

       }

    }
int c()
{
    node *temp=start;
    int count=1;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
void func()
{
    node *temp=start;
    int count=c();
    int mid=count/2;
    while(temp->next!=nullptr)
    {
        for(int i=1;i<=count;i++)
        {

            if(i>mid)
            {
                create(temp->info);
            }
             temp=temp->next;
        }

    }
}
void display()
{
    node *temp1;
    temp1=start;
    cout<<"Start";
    while(temp1!=nullptr)
    {
        cout<<temp1->info<<"->";
        //temp2->info=temp1->info;
        temp1=temp1->next;

    }
        cout<<"END";
        cout<<"start value"<<start->info<<endl;
}
int main()
{
    create(1);
    create(2);
    create(3);
    create(4);
    create(5);
    create(6);
    int l=c();
    cout<<l<<endl;
    display();
    cout<<endl;
    func();
    display();
}
