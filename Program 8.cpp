// PRIME FACTORISATION 

#include<cmath>
#include <iostream>
using namespace std; 
int main()
{
    int n ; 
    cout<<"Enter the number pls :"; 
    cin>>n;
    for(int i=2 ; i<=n ; i++ )
    {
        int ctr = 0 ;
        if(n%i ==0 )
        {
            while(n%i==0)
            {
                n=n/i;
                ctr++; 
            }
            
            cout<<"Factor :"<<i<<" repeats :"<<ctr<<" times\n"; 
            
        }
    }
    
      
    return 0;
}
