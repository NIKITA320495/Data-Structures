#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
    int counter=1;
    while(counter<n-1)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
        counter++;
    }
}
int main()
{
    int arr[5]={23,5,7,0,1};
    bubblesort(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
}
