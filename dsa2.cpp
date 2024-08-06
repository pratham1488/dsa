#include<iostream>
using namespace std;
int main() {
    float v;
    int count = 0;
    cout <<"enter the dropping velocity : "<<endl;
    cin>>vel;
    while(v != 0){
       
        count = count + 1;
        v = v/2;
    }
    cout<<"Number of bounces = "<<count;
    
    return 0;
}
