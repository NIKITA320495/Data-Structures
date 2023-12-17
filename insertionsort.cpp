#include<iostream>
using namespace std;
void insertionsort(int arr[],int n)
{int curr;
    for(int i=1;i<n;i++)
    {
        curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }
}
int main()
{
    int arr[6]={12,45,23,51,19,8};
    insertionsort(arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i];
    }
}
