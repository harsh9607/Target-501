// Codechef problem - Three numbers 
// I took help of this video - https://www.youtube.com/watch?v=m7eof7zZhQk
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		long  x, y, z;
		cin >> x >> y >> z;
	    long A[3] = {x,y,z};
	    sort(A,A+3);
	    
	    if((abs(x-y)%2==0) &&(abs(z-y)%2==0) && (abs(z-x)%2==0) )
	    {
	        cout<<( ( abs(A[1]-A[0]) / 2 ) + ( abs(A[2]-A[0]) / 2 )) <<endl;  
	    }
	    else
	    {
	        cout<<"-1\n"; 
	    }
	}
	return 0;
}
