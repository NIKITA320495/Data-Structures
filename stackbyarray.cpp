#include<iostream>
using namespace std;
int top=-1;
int a[100];
int n;
void push(int x)
{
    if(top==n)
    {
        cout<<"stack overflow";
    }
    else{
    top=top+1;
    a[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow";
    }
    else
    {
        top=top-1;
    }
}
void display()
{
    for( int i=0;i<=top;i++)
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
    cout<<"\t\t\t\tSTACK"<<endl;
    cout<<"\t\t\t\t1.push"<<endl;
    cout<<"\t\t\t\t2.pop"<<endl;
    cout<<"\t\t\t\t3.display"<<endl;
    cout<<"\t\t\t\t4.exit"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice)
    {
        case 1: do
                {
                    cout<<"Enter the value to push";
                    cin>>x;
                    push(x);
                    cout<<"Do you want to continue?";
                    cin>>ch;
                    n++;
                }while(ch=='y');
                break;
        case 2:  do
                { pop();
                cout<<"Do you want to continue?";
                cin>>ch;
                }while(ch=='y');
                break;
        case 3:cout<<"stack: ";
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



