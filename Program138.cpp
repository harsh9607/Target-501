// Climbing Stairs using Dynamic Programming
/*
* You are on stair number N. You need to climb
* down to stair number zero. Find in how many ways 
* can you do that. Note that your step size is equal to
* an element from the array.  
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include <chrono>

using namespace std;
using namespace std::chrono;

unordered_map<int, int64_t> MAP;

int64_t Check_stairs(int n, int A[], int size)
{
	if (MAP.find(n) != MAP.end())
	{
		return MAP[n];
	}
	if (n == 0)
	{
		return 1; 
	}
	if (n < 0)
	{
		return 0; 
	}
	int64_t count = 0; 
	for (int i = 0; i < size; i++)
	{
		count += Check_stairs(n - A[i], A, size);
	}
	MAP[n] = count;
	return count; 
}

int main()
{
	auto start = high_resolution_clock::now();
	
	// DECLARATION OF VARIABLE
	int n = 100; 
	int A[] = { 5,4,3 }; 
	int size = sizeof(A) / sizeof(A[0]);

	// FUNCTION CALL
	int64_t ans = Check_stairs( n, A,size );
	cout << ans;
	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function: "
		<< duration.count() << " microseconds" << endl;


	return 0;

}
