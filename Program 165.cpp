// Number to words ( Indian number System ) 
// Till ninety nine crore ninety nine lacs ninety nine thousand nine hundred  ninety nine

#include <iostream>
using namespace std;
string match(int);
string _Fun_(int);
string digitInWords(int);
string To_Words(int);

// For n>2 
string digitInWords(int n)
{   
    
    
    if(n==0)
    {
        return "" ; 
    }
    string Ans=""; 
    //Ans =  digitInWords(n/10) + " " +match(n%10) +   ; 
    
    if(n<=9)
    {
        Ans = match(n) + " hundred";
    }
    
    else if(n>=9 && n<=999 )
    {
        Ans = _Fun_(n/10)+  " thousand " ; 
        if(n%10)
        { 
            Ans+= match(n%10) + " hundred ";
            
        }
             
    }
    
    else if(n>=1000 && n<=99999) 
    {   
       
         Ans += _Fun_(n/1000) +  " lacs " ; 
         n = n%1000;
         Ans += digitInWords(n);
        
    }
    
  else if(n>99999) 
    { 
      
     Ans += _Fun_(n/100000) +  " crore " ;
     
     n = n%100000;
     Ans += digitInWords(n);
    
    }
    
    
    
    return Ans;
}

// Main Calling function 
string To_Words(int n)
{
    if(n==0)
    {
        return "zero";
    }
    
    int second = n%100;
    string s =  _Fun_(second);
    string f = digitInWords(n/100);
    
    return (f+" "+s) ;
}

// for n<=2 
string _Fun_(int n)
{  
    string ans;
    if(n<=9)
    {
        return match(n);
    }
    
    else if(n<=19 && n>9){
        switch(n)
        {
            case 11 : ans = "eleven";  
                     break;
            case 12 : ans = "twelve";  
                     break;
            case 13 : ans = "thriteen";  
                     break;
            case 14 : ans = "fourteen";  
                     break;
            case 15 : ans = "fifteen";  
                     break;
            case 16 : ans = "sixteen";  
                     break;
            case 17 : ans = "seventeen";  
                     break;
            case 18 : ans = "eighteen";  
                     break;
            case 19 : ans = "nineteen";  
                     break;
            case 10 : ans = "ten";
                     break; 
            default: ans = ""; 
                    break ;     
            
        
        }
    }
    
    else
    {
        int first  = 10* (n/10);
        int second = n%10;
        string  x ; 
        switch(first)
        {
         case 20 : x = "twenty";  
                 break;
        case 30 : x = "thirty";  
                 break;
        case 40 : x = "forty";  
                 break;
        case 50 : x = "fifty";  
                 break;
        case 60 : x = "sixty";  
                 break;
        case 70 : x = "seventy";  
                 break;
        case 80 : x = "eighty";  
                 break;
        case 90 : x = "ninety";  
                 break;
        default: x = ""; 
                break ;       
        }
        ans = x +" "+ match(second) ;
        
    }
    
   
   
    return ans; 
}

// Helper function
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
        case 0 : 
        default: ans = ""; 
                break ;         
    }
    return ans ;
}

int main()
{
    cout<<To_Words(999999999);
    return 0;
}
