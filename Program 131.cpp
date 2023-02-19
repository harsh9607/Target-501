// Dynamic programming - Fibonacci ! 
#include<iostream>
#include<algorithm>
#include<vector>
#include <chrono>


using namespace std;
using namespace std::chrono;



int64_t * A = new int64_t[1000] {0};

int64_t fib(int64_t n , int64_t A[])
{

	if (n == 1)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	if (A[n] != 0)
	{
		return A[n];
	}

	int64_t x = fib(n - 1, A ); 
	A[n - 1] = x; 
	int64_t y = fib(n - 2 ,A );
	A[n - 2] = y; 
	return x+y; 
}

int64_t fib1(int64_t x)
{
	if (x == 0)
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}
	return fib1(x - 1) + fib1(x - 2); 
}


int main()
{   
	auto start = high_resolution_clock::now();
	int64_t x = fib(30, A);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"Using DP " << x << endl;
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	start = high_resolution_clock::now();
	x = fib1(30);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout <<"Not using DP " << x << endl;
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

}

/* 
On my system
Using DP 832040
Time taken by function: 3 microseconds
Not using DP 832040
Time taken by function: 27356 microseconds
*/
