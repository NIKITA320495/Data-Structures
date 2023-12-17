#include<iostream>
using namespace std;
int main()
{
    int n;
    int target;
    cout<<"Enter how many elements?";
    cin>>n;
    int nums[n];
    cout<<"Enter sum target";
    cin>>target;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter elements of array";
        cin>>nums[i];
    }
     for(int i=0;i<n;i++)
    {
       cout<<nums[i];
    }
    cout<<endl;
     for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           if(nums[i]+nums[i+j]==target)
           {
               cout<<i<<i+j;
           }
       }
    }

}





