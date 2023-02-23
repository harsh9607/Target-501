#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t ; 
	cin>>t; 
	while(t--)
    {
        int n;
        cin>>n;
        int A[n+1][n+1] ;
        if(n==1)
        {
            int x; cin>>x; cout<<x<<endl;
        }
        else{
        for(int i=0 ; i<=n ; i++)
        {
            for(int j=0 ; j<=n ; j++)
            {
                A[i][j] = 0 ; 
            }
        }
        
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j=1;j<=i;j++)
            {
                cin>>A[i][j];
            }
        }
        
        // Sol 
        int max_ = 0 ; 
        //YAHA
        for(int i=n-1 ; i>=1 ; i--)
        {
            for(int j=1 ; j<=n ;j++)
            {   
                
                if( j+1 == n+1)
                {
                    A[i][j] += A[i-1][j];
                    if(max_<A[i][j])
                    {
                        max_ = A[i][j];
                    }
                }
                
                else
                {
                    A[i][j] += std::max(A[i+1][j] , A[i+1][j+1]);
                    if(max_<A[i][j])
                    {
                        max_ = A[i][j];
                    }
                }
                
            }
        }
        cout<<max_<<endl;
        
        }
    }
	return 0;
}
