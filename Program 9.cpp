// BENJAMIN BULBS 

#include<cmath>
#include <iostream>
using namespace std; 

void toggle(int A[] , int i )
{
    if(A[i] == 0 )
    {
        A[i] = 1 ; 
    }
    
    else 
    {
        A[i] = 0 ;
    }
    
}

int main()
{
    int n , ctr = 1  ; 
    cout<<"Enter the number pls :"; 
    cin>>n;
    int A[n] = {0}; 
    for(int i=1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            if(i*j<=n)
            {
                toggle(A,i*j-1);
                
            }
            
        }
            
    }
    
 for(int i=0 ; i<n ;i++ )
    {
        cout<<A[i]<<" ";
    }
      
    return 0;
}
