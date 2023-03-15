#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t; 
	while(t--)
	{
	    int n; 
	    cin>>n;
	   
	    
	    map<int,int> Map;
	    for(int i=0 ; i<n ; i++)
	    {   
	        int f ;cin>>f; 
	        Map[f]++; 
	    }
	    
	     if(n%2==1)
	    {
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    int ones = Map[1] , zeros = Map[0]; 
	   if(zeros == n )
	   {
	       cout<<-1<<endl;
	   }
	   else if(ones == n && n==2)
	   {
	       cout<<-1<<endl;
	   }
	   else if ( ones == n )
	   {
	       if(ones % 4 ==0 )
	       {
	           cout<<ones/4<<endl ;
	       }
	       else 
	       {
	           cout<<(n/4) + 2<<endl; 
	       }
	   }
	   else if( ones == zeros)
	   {
	       cout<<0<<endl;
	   }
	   else if( zeros > ones )
	   {
	       cout<<n/2 - ones <<endl; 
	   } 
	   else if (ones > zeros)
	   {
	       int xeros_needed = (n/2) - zeros ; 
	       if(xeros_needed %2 == 0)
	       {
	           cout<<xeros_needed/2<<endl; 
	       }
	       else
	       {
	           cout<<(xeros_needed/2)+2<<endl;
	       }
	   }
	}
	return 0;
}
