//Digit printer tens to ones.
#include <iostream>
using namespace std;

int main()
{
    int n , x = 0  , ctr = 0 ; 
    cout<<"Enter the number "; 
    cin>>n;
    
    
    while(n>0)
    {
        // x is reverse of n so if n = 123  ; x = 321 
        x = x*10 + n%10; 
        n = n/10 ;
        ctr++ ;
    }
    
    // printing X ke digits 
    while(x>0)
    {
        cout<<x%10<<endl ; 
        x = x/10; 
        
    }

    return 0;
}
/* 
n = 321
OUTPUT - 
3
2
1
*/
