#include<iostream>
using namespace std;
int main()
{
    int n,val;
    cout<<"enter how many elements";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter";
        cin>>arr[i];
    }
    cout<<"Enter which value you want to delete";
    cin>>val;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            for(int j=0;j<n;j++)
            {
                arr[i+j]=arr[i+j+1];
            }
        }
    }
    n=n-1;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
