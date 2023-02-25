// HasPath ? Undirected Cyclic Graphs Traversal 

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

bool in_Stack(stack<char> S, char x)
{
	bool flag = false;
	while (!S.empty())
	{
		if (S.top() == x)
		{
			flag = true;
			break;
		}
		S.pop();
	}

	return flag;
}

void hasPath(char Source, char Destination ,  stack<char> S )
{
	bool flag = false; 

	if (S.empty())
	{
		S.push(Source); 

	}

	while (!S.empty())
	{
		if (S.top() == Destination)
		{
			flag = true;
			break; 
		}

		char temp = S.top();
		Visited.insert(S.top());
		S.pop();

		for (auto it : Map[temp])
		{
			if ( Visited.find(it) == Visited.end() && (!in_Stack(S, it)))
			{
				S.push(it);
			}
		}
	}

	if (flag)
	{
		cout << "Found a path from " << Source << " to " << Destination<<endl;
	}
	else
	{
		cout << "There is No Path from " << Source << " to " << Destination << endl; 
	}
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
	PrintMap();
	 
	cout << "\n Has path ? : "; hasPath('i','o', S);
	Visited = {};

	return 0;
}
