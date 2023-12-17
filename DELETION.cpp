#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
node *start=nullptr;
node *temp;
void create(int info)
{
    node *newnode=new node;
    temp=start;
    newnode->info=info;
    newnode->next=start;
    start=newnode;
}
void Delete_from_beg()
{
    node * temp;
    temp=start;
    start=start->next;
    free(temp);
}
void Delete_from_end()
{
    node *temp1;
    node *temp2;

    temp1=start;
    temp2=start;
    while(temp1->next!=nullptr)
    {
        temp2=temp1;

        temp1=temp1->next;

    }
cout<<temp2->info<<endl;
temp2->next=nullptr;
free(temp1);

}
void Delete_from_mid()
{
    int val;
    cout<<"Enter the value you want to delete";
    cin>>val;
    node *temp1=start;
    node *temp2=temp1;
    while(temp1!=nullptr)
    {
        temp2=temp1;
        temp1=temp1->next;
        if(temp1->info==val)
        {
         temp2->next=temp1->next;
         break;
        }
    }
    free(temp1);
}
void display()
{ node *temp1;
    temp1=start;
    cout<<"Start"<<start->info;
    while(temp1!=nullptr)
    {
        cout<<temp1->info<<"->";
        temp1=temp1->next;
    }
        cout<<"END";
}
int main()
{
    int choice,x;
    char c,ch;
    do
    {
    cout<<"\t\t\t\tDELETION"<<endl;
    cout<<"\t\t\t\t1.Enter elements"<<endl;
    cout<<"\t\t\t\t2.Delete from beginning"<<endl;
    cout<<"\t\t\t\t3.Delete from mid"<<endl;
    cout<<"\t\t\t\t4.Delete from end"<<endl;
    cout<<"\t\t\t\t5.Exit"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch (choice)
    {
        case 1: do
                {
                cout<<"Enter";
                cin>>x;
                create(x);
                cout<<"more";
                cin>>ch;
                }while(toupper(ch)=='Y');
                display();
        break;
        case 2:Delete_from_beg();
        display();
        break;
        case 3:Delete_from_mid();
        display();
        break;
        case 4:Delete_from_end();
        display();
        break;
        case 5: exit(0);
        break;
        default:
            cout<<"Wrong choice";
    }
     cout<<"Do you want to continue?";
    cin>>c;
}while(toupper(c)=='Y');
}
