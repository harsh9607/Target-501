// Find ALL POSSIBLE Cases where Sum can be obtained using elements of the array (used any number of times )  
/*
For example > N = 7  & Array = [1,3,4]; 
Ans = 1->1->1->1->1->1->1->
      1->1->1->1->3->
      1->1->1->3->1->
      1->1->1->4->
      1->1->3->1->1->
      1->1->4->1->
      1->3->1->1->1->
      1->3->3->
      1->4->1->1->
      3->1->1->1->1->
      3->1->3->
      3->3->1->
      3->4->
      4->1->1->1->
      4->3->

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void canSum(int n, int A[] , int size , vector<int> V  )
{   
	if (n == 0)
	{   for(auto it : V)
		{
		cout << it <<"->";
		}
	    cout << endl;
	    return; 
	}
	if (n < 0)
	{
		return ; 
	}
	 
	for (int i = 0; i < size; i++)
	{
		V.push_back(A[i]);
	    canSum(n - A[i], A, size, V);
		V.pop_back();
	}

}



int main()
{
	vector<int>V; 
	auto start = high_resolution_clock::now();
	int A[6] = { 1,2,3,4,5,7 };
    canSum(7,A,6,V);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
	
	cout << "\nTime taken by function: "
		<< duration.count() << " microseconds" << endl;


	return 0; 

}
