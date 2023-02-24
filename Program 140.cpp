// Depth First Search 
#include <iostream>
#include<unordered_map> 
#include<algorithm>
#include<stack>
using namespace std;

unordered_map<char , vector<char> > Map;

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

void DFS(char Source , stack<char>&S )
{
	S.push(Source);
	while (!S.empty())
	{
		cout << S.top(); 
		char temp = S.top();
		S.pop();
		for(auto it : Map[temp])
		{
			S.push((char)it);
		}

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
	vector<char> V = {'b','c'};
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
	DFS('a',S);
	return 0;
}
