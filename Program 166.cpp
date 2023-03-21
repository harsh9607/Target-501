// How many stairs. 
/*
Problem : You can move either 1 step or 2 steps forward.
          Find how many way exist to climb upto the nth-step.  
Approach : Dynamic programming 
*/
#include <iostream>
using namespace std;

int A[100] = {0};
static int x=0,y=0; 
int howManyStairsDP(int n )
{   y++;
    if(A[n]!=0)
    {
        return A[n];
    }
    if(n==0)
    {
        return 1 ; 
    }
    if(n<0)
    {
        return 0 ; 
    }
    
    A[n-1] =  howManyStairsDP(n-1);
    A[n-2] =  howManyStairsDP(n-2);
    A[n]   =  A[n-1] + A[n-2]; 
    return A[n]; 
}

int howManyStairs(int n )
{
    x++;
    if(n==0)
    {
        return 1 ; 
    }
    if(n<0)
    {
        return 0 ; 
    }
    
    int ans = howManyStairs(n-1) + howManyStairs(n-2); 
    return ans; 
}

// Tabulisation 
int Arr[50] = {0}; 

void Tabuliser(int n)
{   
    Arr[1]= 1; 
    Arr[2]= 2; 
    for( int i=3 ; i<=n ; ++i )
    {
        Arr[i] =  Arr[i-1] + Arr[i-2];
    }
}

// BEST Solution : Space Optimisation
void Optimised(int n)
{
    int prev=1,curr=2,ans; 
    for( int i=3 ; i<=n ; ++i )
    {
        ans   = prev+curr; 
        prev  = curr; 
        curr  = ans; 
    }
    cout<<ans<<endl; 
}

int main()
{
    cout<<howManyStairs(15)<<" "<<x<<endl; 
    cout<<howManyStairsDP(15)<<" "<<y<<endl;
    Tabuliser(37);
    cout<<Arr[15]<<endl;
    Optimised(15);
    return 0;
}
