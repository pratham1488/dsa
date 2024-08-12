#include<iostream>
  using namespace std;
 
 int binarySearch(int arr[], int n, int x)
  {
     int start= 0;
     int end= n-1 ;
     int mid= (end + start)/2 ;
     while(start<=end)
     {
        if(arr[mid]==x)
         return mid;
 
         if(x> arr[mid])  
         {
             start= mid+1 ;
         }
         else{             
           end= mid-1;
         }
        mid= (end + start)/2;  
    }
   return -1;
 }

 int main()
 {
    int a1[6]={1,2,3,4,5,6};  
    int a2[5]={11,13,16,18,19};
    int ans = binarySearch(a1,6,0);
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }
    else{
     cout<<"Index of '0' : "<<ans<<endl;   
    }
    ans = binarySearch(a2,5,16);
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }
    else{
     cout<<"Index of '16' : "<<ans<<endl;   
    }
    return 0;
 }
