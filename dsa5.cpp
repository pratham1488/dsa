#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout<<"Size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter consecutive elements in array: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int start=arr[0];
    int end=arr[0]+size;
    int xorr=0;
    int xornew=0;
    for(int i=start;i<=end;i++)
    {
        xorr=xorr^i;
    }
    for(int i=0;i<size;i++)
    {
        xornew=xornew^arr[i];
    }
    int answer=xorr^xornew;
    cout<<"Answer is : "<<answer;



    return 0;
}
