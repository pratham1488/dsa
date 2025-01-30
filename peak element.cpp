#include<iostream>
using namespace std;
int Peak(int arr[],int n){
    if(arr[0]>arr[1]){
        return arr[0];
    }
    else{
        for(int i=1;i<n-2;i++){
            if(arr[i]>arr[i-1]&& arr[i]>arr[i+1]){
                return arr[i];
            }
        }
    }
    if(arr[n-1]>arr[n-1]){
        return arr[n-1];
    }
}
int main(){
    int arr[]={2,3,4,55,6,2,8};
    cout<<"Peak element is : "<<Peak(arr,7);
    return 0;
}
