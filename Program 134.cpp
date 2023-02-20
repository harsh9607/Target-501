// Find min nos from array thatadd up to the target sum.Repetiton is allowed   
#include<iostream>
#include<algorithm>
#include<vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


void bestSum(int n,int A[],int size, vector<int> V,vector<int>& V2 )
{
	if (n == 0)
	{   
		if(V2.empty())
		{
			V2 = V;
		}
		if (V.size() < V2.size())
		{
			V2 = V; 
		}
		return ;
	}

	if (n < 0)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		V.push_back(A[i]);
		bestSum(n - A[i], A, size, V,V2);
		V.pop_back();
	}

}


int main()
{
	vector<int>V; 
	vector<int> V2 ;
	auto start = high_resolution_clock::now();
	int A[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(A) / sizeof(A[0]); 
	bestSum(30, A, size, V,V2);
	cout << "Bestsum is made using: "; 
	for (auto it : V2)
	{
		cout << it << " ";
	}
	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	cout << "\nTime taken by function: "
		<< duration.count() << " microseconds" << endl;


	return 0; 

}
