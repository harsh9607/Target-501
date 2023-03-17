// Djikstras algorithm 
#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>

using namespace std;

vector<int> djikstraAlgorithm(vector<vector<int>>& V, int nodes, int edges, int source)
{
	// Step 1 : Create an adjaceny list using given Vector
	unordered_map<int, list<pair<int,int>>> adj;
	// Pair<node,distance>
	// 0 -> { [1,7] , [2,1], [3,2] }
	
	for (int i = 0; i < edges ; i++)
	{
		int u = V[i][0];
		int v = V[i][1];
		int w = V[i][2];

		// Pushing Twice for both nodes as its an undirected graph
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));

	}
	
	// Lets create our Answer Vector
	vector<int> dist(nodes);
	
	// Lets initialise all Distance to infinity 
	for (int i = 0; i < nodes; i++)
	{
		dist[i] = INT_MAX ; 
	}
	
	// Now lets create our set <distance to reach the node , node > 
	set<pair<int, int>> st; 
	// Source ka distance is zero 
	dist[source] = 0; 
	st.insert(make_pair( dist[source], source));

	// MAIN LOGIC OF DJIKSTRA 
	while (!st.empty())
	{
		// fetch top record ie. st.begin()
		pair<int,int> top = *(st.begin());

		int dist_to_u = top.first; 
		int u = top.second;

		// Erase this element as its no longer needed
		st.erase({dist_to_u, u});

		for (auto it : adj[u])
		{
			//  u to v's  dist is w 
			int v = it.first; 
			int w = it.second; 

			

			int dist_of_v_from_src = w + dist_to_u; 
			if (dist_of_v_from_src < dist[v])
			{   
				// If already exist remove it
				auto record = st.find(make_pair(dist[v],v));
				if (record != st.end())
				{
					st.erase(record);
				}

				// Update to new min distance 
				dist[v] = dist_of_v_from_src;
				st.insert(make_pair(dist[v],v));
			}

		}
		

	}
	return dist; 
}

void printVec(vector<vector<int>> V)
{
	cout << " + Printing Vector \n";
	for (vector<int> it : V)
	{
		vector<int> X = it;
		for (auto val : X)
		{
			cout << val << " ";
		}
		cout << endl;
	}
	cout << " - Printing Complete \n";
}

int main() {
	// your code goes here
	int nodes = 5;
	int edges = 7;
	int src = 0;
	
	vector<vector<int>>V = { {0,1,7},{0,2,1},{0,3,2},{1,2,3},{1,3,5},{1,4,1},{3,4,7} };
	printVec(V);
	
	vector<int> ans = djikstraAlgorithm(V,nodes,edges,src);
	
	cout << "From node Src = " << src << " minimum distance \n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << "To node " << i << "  = " << ans[i] << endl;
	}

	return 0;
}
