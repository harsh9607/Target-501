//Digit counter  
#include <iostream>

using namespace std;

int main()
{
    int n , ctr = 0 ; 
    cout<<"Enter the number "; 
    cin>>n;
    
    while(n>0)
    {
        n = n/10 ; 
        ctr++ ;
    }

    cout<<ctr;    

    

    return 0;
}
