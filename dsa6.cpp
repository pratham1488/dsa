#include<iostream>
using namespace std;
void Pattern(int len,int n,char a[])
{
    if(len == n)
    { cout<<"Pattern : ";
   for(int i= 0 ;i<n;i++ ){
       cout<<a[i];
    }
     cout<<endl;
     
     return;
   }
    else
    {
        a[len]='T';
        Pattern(len+1,n,a);
        a[len]='F';
        Pattern(len+1,n,a);
    }
}
int main(){
    int n;
    cout<<"Enter the Length : ";
    cin>>n;
    char a[n];
    cout<<endl;
    Pattern(0,2,a);
    
    return 0;
}
