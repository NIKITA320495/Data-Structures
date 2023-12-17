#include<iostream>
using namespace std;
struct queue
{
     int info;
     queue *next;
};
queue *f=nullptr;
queue *e=nullptr;
void insert(int info)
{
    queue *newnode= new queue;
    newnode->info=info;
    newnode->next=nullptr;
    if(e==nullptr)
    {
        f = e= newnode;
    }
    else
    {
        while(e->next!=nullptr)
        {
            e=e->next;
        }
        e->next=newnode;
    }
}
void del()
{
    queue *temp;
    temp=f;
    if(f==nullptr)
    {
        cout<<"Queue underflow";

    }
    else
    {
        temp=temp->next;
        free(f);
        f=temp;
    }
}
void display()
{
    queue *temp1;
    temp1=f;
    cout<<"Front";
    if(f==nullptr)
    {
        cout<<"Queue empty";
    }
    else{
    while(temp1!=nullptr)
    {
        cout<<temp1->info<<"->";
        //temp2->info=temp1->info;
        temp1=temp1->next;

    }
        cout<<"END";
        cout<<"start value"<<f->info<<endl;


}
}
int main()
{
    int x,choice;
    char c,ch;
    do
    {
        cout<<"\t\t\t\tQUEUE"<<endl;
        cout<<"\t\t\t\t1.INSERTION"<<endl;
        cout<<"\t\t\t\t2.DELETION"<<endl;
        cout<<"\t\t\t\t3.EXIT"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: do
                {
                cout<<"Enter";
                cin>>x;
                insert(x);
                cout<<"more";
                cin>>ch;
                }while(toupper(ch)=='Y');
                display();
                break;
            case 2:
                del();
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"wrong choice";
                break;

            }
             cout<<"Do you want to continue?";
    cin>>c;
}while(toupper(c)=='Y');

}



