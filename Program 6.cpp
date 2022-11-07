#include<cmath>
#include <iostream>
using namespace std; 
int main()
{
    int n,r=0 ; 
    cout<<"Enter a number : " ; 
    cin>> n ; 
    cout<<"Enter places of rotation ie Pivot point "; 
    cin>>r;
    
    // reverse a  bloody number 
    
    int x = pow(10,r) ; 
    
    int first_part = 0 , second_part =0 ;
    
    first_part = n%x; 
    second_part = n/x; 
    cout<<first_part<<second_part;

    return 0;
}
