
#include<cmath>
#include <iostream>
using namespace std; 
int main()
{
    // LCM and HCF 
    int a, b, i=1,j=1; 
    cout<<"Enter the numbers" ; 
    cin>>a>>b;
    
    // LCM 
    do
    {
        if( a*i==b*j)
        {
           
            break; 
            
        }
        
        else if( a*i<b*j)
        {
            i++;
              
        }
        else
        {
            j++; 
           
        }
        
    }while(a*i !=b*j ); 
    
    cout<<"LCM = "<<a*i;
    int hcf = ( a*b ) / ( a*i );
    cout<<endl<<"HCF = "<<hcf; 
    
    return 0;
}
