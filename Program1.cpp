// PRIME NUMBERS IN A RANGE.

#include <iostream>
#include<cmath> 

using namespace std;

int main()
{
    // print all primes in a range
    int low , high  ;
    cout<<"Enter low and high :";
    cin>>low>>high; 
    
   
        for(int j= low ; j<=high ; j++ )
        {   int flag = 0 ; 
        
            for( int i=2 ; i<= sqrt(j) ; i++ )
            {
                
                if( j%i == 0 )
                {
                    flag = 1 ;
                }
                
            
            } 
            
            if(flag == 0 )
            {
                cout<<j<<endl; 
            }
        
        }
    
    return 0;
}
