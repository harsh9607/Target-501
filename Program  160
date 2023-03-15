//Codechef - Sticks
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	
	while(t--)
	{
	    map<int,int>Map;
	    int x ; 
	    cin>>x;
	    if(x<4)
	    {
	        cout<<-1<<endl;
	        continue; 
	    }
	    
	    vector<int> V;
	    for(int i=0 ; i<x; i++)
	    {
	        int y; cin>>y;
	        V.push_back(y);
	        Map[y]++;
	    }

	   vector<int> Vec; 
	    for( auto it : Map)
	    {
	        if(it.second >= 2  )
	        {
	           while(it.second--) 
	           Vec.push_back(it.first); 
	        }
	    }

	    if(Vec.size()<4)
	    {
	        cout<<-1<<endl;
	    }
	    
	    else
	    {
	        for(int i=Vec.size()-1 ; i>=3 ; i--)
	        {     
	            int a = Vec[i]; 
	            int b = Vec[i-1];
	            int c = Vec[i-2]; 
	            int d = Vec[i-3];
	           // cout<<a<<b<<c<<d;
	            if(a==b && c==d)
	            {
	                cout<<a*c<<endl;
	                break; 
	            }
	        }
	    }
	    
	     
	   
	// t--   
	}
	
	return 0;
}
