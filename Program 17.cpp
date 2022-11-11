// ARROWS 
#include<cmath>
#include <iostream>
using namespace std; 

int main()
{

   int n , space, stars = 1 , d= 2 ; 
   cout<<"Enter N :"; 
   cin>>n;
   space = -n/2; 
   
   for(int i=1  ; i<=n ; i++ )
   {
        int x = abs(space) ; 
        while(x>0)
        {
            cout<<" "; 
            x--; 
        }
        
    
        for(int y = 1 ; y<=stars ; y++)
        {
            if(y <= stars/2 && i != ( (n/2) + 1 ) )
            {
                cout<<" ";        
            }
        
            else
            {
                cout<<"*";
            }
        
            
        }
        
        if(i>n/2)
        {
            d=-2;
        }
        
        space++;
        stars+=d ;
        cout<<endl; 
   }
   
   
    return 0;
}
