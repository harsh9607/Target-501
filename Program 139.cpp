#include <iostream>
#include<unordered_map>
using namespace std;

unordered_map<int64_t, int64_t>Map; 
int64_t Bitlandian_Coins(int64_t n)
{
    if(Map.find(n)!=Map.end())
    {
        return Map[n]; 
    }
    
    if(n<=2)
    {
        return n ;
    }
    Map[n] = std::max( n , Bitlandian_Coins(n/2) + Bitlandian_Coins(n/3) + Bitlandian_Coins(n/4) ) ;
    
    return Map[n];
}

int main() {
	// your code goes here
       int64_t x ; 
       while(cin>>x)
        {   
            int64_t ans = Bitlandian_Coins(x); 
            cout<<ans<<endl;
        }
	return 0;
}
