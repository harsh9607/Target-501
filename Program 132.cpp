// Dynamic programming Gridtraveller ! 
#include<iostream>
#include<algorithm>
#include<vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int o=0;
int A[100][100] = { 0 };

int gridTravellerDP(int m, int n , int A[][100])
{
	if (m == 1 && n == 1)
	{
		return 1; 
	}
	if (m == 0 || n == 0)
	{
		return 0;
	}
	if (A[m][n] != 0)
	{
		o++; 
		return A[m][n];
	}
	A[m][n] = gridTravellerDP(m-1, n,A) + gridTravellerDP(m, n - 1,A); 
	return A[m][n];
}


int gridTraveller(int m, int n)
{
	if (m == 1 && n == 1)
	{
		return 1;
	}
	if (m == 0 || n == 0)
	{
		return 0;
	}
	
	
	return gridTraveller(m - 1, n) + gridTraveller(m, n - 1);
	
}

int main()
{   
	auto start = high_resolution_clock::now();
	int64_t x = gridTravellerDP(7, 5 , A );
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"Using DP " << x << endl;
	cout << "Total Optimisations called =" << o << endl;
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	start = high_resolution_clock::now();
	x = gridTraveller(7, 5);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout <<"Not using DP " << x << endl;
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

}
