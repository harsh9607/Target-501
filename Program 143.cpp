// Find if an element exists in a Directed Acyclic Graph  

#include <iostream>
#include<unordered_map> 
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

unordered_map<char, vector<char> > Map;

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

void DFS(char Source, stack<char>& S)
{
	S.push(Source);
	while (!S.empty())
	{
		cout << S.top();
		char temp = S.top();
		S.pop();
		for (auto it : Map[temp])
		{
			S.push((char)it);
		}

	}


}

void BFS(char Source, queue<char>& Q)
{
	Q.push(Source);
	while (!Q.empty()) {
		cout << Q.front();
		char temp = Q.front();
		Q.pop();
		for (auto it : Map[temp])
		{
			Q.push((char)it);
		}
	}
}


void HasPath(char Source, char destination)
{
	// BFS search and DFS search
	stack<char> S; 
	queue<char> Q;
	int flag = -1; 
	// BFS 
	Q.push(Source);
	while (!Q.empty())
	{   
		if (Q.front() == destination)
		{
			flag = 1;
			break;
		}

		for (auto it : Map[Q.front()])
		{
			Q.push(it);
		}
		
		if(!Q.empty())
		Q.pop();

	}

	if (flag == 1)
	{
		cout << "Element Discovered " << endl;
		return; 
	}

	// If not found via BFS then lets try DFS
	else
	{
		// DFS 
		S.push(Source); 
		while (!S.empty())
		{
			if(S.top() == destination)
			{
				flag = 1; 
				break; 
			}
			char temp = S.top(); 
			if (!S.empty())
			{
				S.pop();

			}

			for (auto it : Map[temp])
			{
				S.push(it);
			}

			

		}
	}
	
	if (flag == 1)
	{
		cout << "Element Discovered " << endl;
		return;
	}
	
	else
	{
		cout << "ELement is ABSENT\n";
	}
}
int main() {
	/* your code goes here
	 Graph
	Adjacency List
	{
	 a : b , c
	 b : d
	 c : e
	 d : f
	 e : []
	 f : []
	}
	*/
	stack<char> S;
	queue<char> Q;
	vector<char> V = { 'b','c' };
	Map['a'] = V;
	V = { 'd' };
	Map['b'] = V;
	V = { 'e' };
	Map['c'] = V;
	V = { 'f' };
	Map['d'] = V;
	V = {};
	Map['e'] = V;
	Map['f'] = V;

	PrintMap();
	cout << "DFS travel -"; DFS('a', S);
	cout << endl;
	cout << "BFS travel -"; BFS('a', Q);
	cout << endl;
	HasPath('a','z');

	return 0;
}
