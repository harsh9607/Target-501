// Connected components in a Graph 

#include <iostream>
#include<unordered_map> 
#include<algorithm>
#include<stack>
#include<queue>
#include<set>

using namespace std;

unordered_map<char, vector<char> > Map;
set<char> Visited;

void PrintMap()
{
	for (auto it : Map)
	{
		cout << it.first << " -> ";
		for (auto it2 : it.second)
		{
			cout << it2 << "\t";
		}
		cout << endl;
	}
}

void Connected_Components()
{
	int ctr = 0; 
	stack<char> S; 
	
	for (auto it : Map)
	{
		 
		if (Visited.find(it.first) == Visited.end())
		{
			S.push(it.first);
			ctr++;
		}


		while (!S.empty())
		{
			
			Visited.insert(S.top()); 
			char temp = S.top(); 
			S.pop(); 
			for (auto it2 : Map[temp])
			{
				if (Visited.find(it2) == Visited.end())
				{
					S.push(it2); 
				}
			}
		}

		
	}

	cout << "Total Connected components are " << ctr<<endl ;
}


void add_Undirected_Edge(char a, char b)
{   
	Map[a].push_back(b);
	Map[b].push_back(a);
}

int main() {
	/* your code goes here
	 Undirected Graph
	 {
	 [i,j];
	 [k,i];
	 [m,k];
	 [k,l];
	 [o,n];
	 }
	Adjacency List
	{
	 
	}
	*/
	stack<char> S;
	queue<char> Q;
	
	add_Undirected_Edge('i', 'j');
	add_Undirected_Edge('k', 'j');
	add_Undirected_Edge('k', 'i');
	add_Undirected_Edge('m', 'k');
	add_Undirected_Edge('k', 'l');
	add_Undirected_Edge('o', 'n');
	add_Undirected_Edge('h', 's');
	PrintMap();
	 
	

	Connected_Components();

	return 0;
}
