#include<iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
node*start=nullptr;
void create(int info)
{
    node *newnode=new node;
    newnode->info=info;
    newnode->next=start;
    start=newnode;
}
void insertend(int info)
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
node*temp1;
void insertmid(int info,int val)
{
   node *newnode=new node;
   newnode->info=info;
    temp1=start;
   while(temp1!=nullptr)
   {
       if(temp1->info==val)
       {
           newnode->next=temp1->next;
           temp1->next=newnode;
           temp1=newnode;
       }
       temp1=temp1->next;
   }
}
void display()
{
    node *temp2;
    temp2=start;
    cout<<"Start";
    while(temp2!=nullptr)
    {
        cout<<temp2->info;
        cout<<"<";
        temp2=temp2->next;
    }
    cout<<"End";

}
int main()
{   int x;
int choice;
    char ch,c;
    do
    {
    cout<<"\t\t\t\tINSERTION"<<endl;
    cout<<"\t\t\t\t1.IN BEGINNING"<<endl;
    cout<<"\t\t\t\t2.IN MIDDLE"<<endl;
    cout<<"\t\t\t\t3.AT THE END"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
             do
                {
                cout<<"Enter";
                cin>>x;
                create(x);
                cout<<"more";
                cin>>ch;
                }while(toupper(ch)=='Y');
                display();
        break;
        case 2:
            {
                do

                {
                int val;
                cout<<"Enter the value after which you want to insert the value";
                cin>>val;
                cout<<"Enter the value to insert";
                cin>>x;
                insertmid(x,val);
                cout<<"more";
                cin>>ch;
                }while(toupper(ch)=='Y');
                display();
            }
            break;
        case 3:do
                {
                cout<<"Enter the value to insert at end";
                cin>>x;
                insertend(x);
                cout<<"more";
                cin>>ch;
                }while(toupper(ch)=='Y');
                display();

        break;
        default:
            exit(0);
    }
    cout<<"Do you want to continue?";
    cin>>c;
}while(toupper(c)=='Y');
}
