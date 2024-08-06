#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the size of the array : "<<endl;
    cin>>n;
    int a[10]={2,3,4,5,6,7,8,2,3};
    int b[10]={0};
    int c=1;
    for (int i=0;i<n;i++) {
        c=c*a[i];
    }
    cout<<"elements of b[j] are : "<<endl;
    for (int i=0;i<n;i++) {
        cout<<c/a[i]<<endl;
    }
     return 0;
}
