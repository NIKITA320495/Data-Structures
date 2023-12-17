#include<iostream>
using namespace std;
void selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minindex=i;
        for(int j=i+1;j<n;j++)
        { if(arr[j]<arr[minindex])
        {
            minindex=j;
        }
    }
    swap(arr[i],arr[minindex]);
    }

}
int main()
{
    int arr[6]={12,6,3,9,0,7};
    selectionsort(arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]
;    }
}
