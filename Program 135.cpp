// Find min nos from array thatadd up to the target sum.Repetiton is allowed   
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include <chrono>

using namespace std;
using namespace std::chrono;

map<int, vector<int>>Map; 

void bestSum(int n, int A[], int size, vector<int> V, vector<int>& V2 ,  int Val)
{	


	if (n == 0)
	{   
		if (V2.empty())
		{
			V2 = V;
		}
		if (V.size() < V2.size())
		{
			V2 = V;
		}
		
		Map[Val] = V2; 
		return;
	}
	else if (n < 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		V.push_back(A[i]);
		if (Map[n - A[i]].empty()) {
			bestSum(n - A[i], A, size, V, V2, Val);
		}
		else
		{
			if (V2.empty() || Map[n - A[i]].size() + V.size() < V2.size())
			{
				// V2  = V + Map{}
				while (!V2.empty())
				{
					V2.pop_back();
				}
				for (int k = 0; k < Map[n - A[i]].size(); k++)
				{
					V2.push_back(Map[n - A[i]][k]);

				}
				for (int k = 0; k < V.size(); k++)
				{
					V2.push_back(V[k]);

				}
			}

		}
		V.pop_back();
	}

}


int main()
{
	vector<int>V;
	vector<int> V2;
	auto start = high_resolution_clock::now();
	int A[] = { 1,2,5 };
	int size = sizeof(A) / sizeof(A[0]);
	int n = 75; 
	for (int i = 1; i <= n; i++) {
		bestSum(i, A, size, V, V2, i);
		Map[i] = V2; 
		cout << "For i =" << i << " V2: ";
		for (auto it : Map[i])
		{
			cout << it << " ";
		}
		cout << endl;
		while (!V2.empty())
		{
		 V2.pop_back();
		}

	}

	cout << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function: "
		<< duration.count() << " microseconds" << endl;


	return 0;

}
