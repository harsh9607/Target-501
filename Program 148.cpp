// Shortest path in a fully connected undirected graph
#include<iostream>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std; 

unordered_map<char, vector<char>> Map;
std::set<char> Set; 

void add_edge(char x, char y)
{
	Map[x].push_back(y);
	Map[y].push_back(x);
}

void print_map()
{
	for (auto it : Map)
	{
		cout << it.first <<" -> ";
		for (auto it2 : it.second)
		{
			cout << it2 << " , ";
		}
		cout << endl;
	}
}

void shortest_path(char source , char destination , queue<char>Q1 , queue<char>Q2 )
{
	int length = 0; 
	Q1.push(source);
	Set.insert(source); 
	while (!Q1.empty()) {

		char temp = Q1.front();
		Q1.pop();
		Set.insert(temp);
		if(temp == destination)
		{
			break; 
		}

		for (auto it : Map[temp])
		{ 
	
			if (Set.find(it) == Set.end())
			{
				Q2.push(it);
				
			}
		}
		
		if (Q1.empty()) {
			while (!Q2.empty())
			{
				Q1.push(Q2.front());
				Q2.pop();
			}
			length++;
		}
	}
	cout << length; 
}

int main()
{

// Adjacency matrix 
/*   undirected graph
	edges 
	[w x ]
	[x y ]
	[z y ]
	[z v ]
	[w v ]

*/
	queue<char> Q1,Q2;
	
	add_edge('w', 'x');
	add_edge('x', 'y');
	add_edge('z', 'y');
	add_edge('z', 'v');
	add_edge('w', 'v');
	

	
	print_map();
	cout << endl << "Shortest path= "; shortest_path('w', 'z', Q1,Q2);
	return 0; 

}
