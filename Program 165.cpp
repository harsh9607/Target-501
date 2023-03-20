// Number in word
#include <iostream>
using namespace std;
string match(int); 
string digitInWords(int n)
{
    if(n==0)
    {
        return "" ; 
    }
    
    string Ans =  digitInWords(n/10) + " " +match(n%10)  ; 
    return Ans;
}

string match(int n)
{   string ans; 
    switch(n)
    {
        
        case 1 : ans = "one";  
                 break;
        case 2 : ans = "two";  
                 break;
        case 3 : ans = "three";  
                 break;
        case 4 : ans = "four";  
                 break;
        case 5 : ans = "five";  
                 break;
        case 6 : ans = "six";  
                 break;
        case 7 : ans = "seven";  
                 break;
        case 8 : ans = "eight";  
                 break;
        case 9 : ans = "nine";  
                 break;
        case 0 : ans = "zero";  
                 break;
        default: ans = ""; 
                break ;         
    }
    return ans ;
}

int main()
{
    cout<<digitInWords(431);
    return 0;
}
