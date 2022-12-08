#include <iostream>
#include<cmath>
#include<climits>
using namespace std; 

int main() {
    
    int n=5 ; 
    int A[n] = { 1,2,4,15,26}; 
    int a = INT_MIN ; 
    int b = INT_MAX ; 
    for(int i = 0 ; i < sizeof(A)/sizeof(A[0]); i++)
    {
        if( A[i] > a )
        {
            a = A[i] ;
        }
        
        if(A[i] < b)
        {
            b = A[i] ; 
        }
    }
  
    cout<<"SPAN OF ARRAY = " << a-b;
    return 0;
}
