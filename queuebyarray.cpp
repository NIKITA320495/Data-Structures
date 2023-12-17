#include<iostream>
using namespace std;
int a[100];
int f=-1;
int r=-1;
int n;
void ins(int x)
{
    if((f==-1)&&(r==-1))
    {
        f=0;
        r=0;
        a[f]=x;
    }
    else if (r<=(n-1))
    {
        a[++r]=x;
    }
    else
    {
        cout<<"Queue overflow";
    }
}
void del()
{
    if((f==-1)&&(r==-1))
    {
        cout<<"Queue Empty";
    }
    else
    {
        f++;
    }
}
void display()
{
    for( int i=f;i<=r;i++)
    {
        cout<<a[i];
    }
}
int main()
{
    int choice;
    int x;
    char ch,c;
    do{
    cout<<"\t\t\t\tQUEUE"<<endl;
    cout<<"\t\t\t\t1.insert"<<endl;
    cout<<"\t\t\t\t2.delete"<<endl;
    cout<<"\t\t\t\t3.display"<<endl;
    cout<<"\t\t\t\t4.exit"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:do
                {
                    cout<<"Enter the value to insert";
                    cin>>x;
                    ins(x);
                    cout<<"Do you want to continue?";
                    cin>>ch;
                    n++;
                }while(ch=='y');
                break;
        case 2:  do
                {
                del();
                cout<<"first element deleted"<<endl;
                cout<<"Do you want to continue?";
                cin>>ch;
                }while(ch=='y');
                break;
        case 3:cout<<"QUEUE: ";
            display();
            cout<<"\n";
                break;
        case 4:exit(0);
                break;
        default:cout<<"Wrong choice";
    }
    cout<<"do you want to go back to menu";
    cin>>c;
}while(c=='y');
}
