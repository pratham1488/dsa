#include <iostream>
using namespace std;
int add(int a[], int len){
    if(len==0){
        return a[0];
    }
    return (a[len]+add(a,len-1));
}
int main() {
    cout<<"Length ";
    int n;
    cin>>n;
    int array[n];
    cout<<"Enter numbers to be added  ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"Sum "<<add(array,n-1);
}
