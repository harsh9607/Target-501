// INVERSE OF A NUMBER 
#include <iostream>
#include<cmath>
using namespace std;

int main()
{   
    int n,x,ctr = 0, inv =0 ; 
    
    cout<<"Enter the number ";
    cin>>n; 
    x=n ; 
    while(x>0)
    {
        x=x/10;
        ctr++; 
    }
    
    for(int i =1 ; i<=ctr ;  i++ )
    {
        int expo = n%10 ; 
        expo--; 
        inv = (pow(10, expo)) * i + inv; 
        n=n/10; 
    }
    
    cout<<inv; 
    
    return 0;
}
