//deletion at any point 
#include<iostream>
using namespace std;

int main()
{
     int i,n;
     cout<<"enter the size of array : ";
     cin>>n;
     int arr[n];
     cout<<"enter the value: \n";
     for(i=0;i<n;i++)
     {
        cin>>arr[i];
     }
     for(i=0;i<n;i++)
     {
        cout<< " " <<arr[i] ;
     }
        int index;
        cout<<"\n enter the position on which number is to be delelted: \n";
        cin>>index;
        int number;
        for (i=index;i<n-1;i++)
        {
         arr[i]=arr[i+1];
        }
        arr[n-1] = 0;
        n-=1;
        for(i=0;i<n;i++)
     {
        cout<< " " <<arr[i] ;
     }
     return 0;
     }
