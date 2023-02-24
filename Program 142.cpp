// Depth First Search 
#include <iostream>
#include<unordered_map> 
#include<algorithm>
#include<stack>
#include <cctype>
#include<queue>

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
	if(S.empty())
	S.push(Source);

	
	cout << S.top(); 
	char temp = S.top();
	S.pop();
	for(auto it : Map[temp])
	{
		S.push(it);
	}

	if(!S.empty())
	DFS(S.top() , S);

	   
}

void BFS(char Source, queue<char>& Q)
{	if(Q.empty())
	Q.push(Source);

	cout << Q.front();
	char temp = Q.front();
	Q.pop();
	for (auto it : Map[temp])
	{
			Q.push((char)it);
	}

	if (!Q.empty())
		BFS(Q.front(), Q);
	
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
	cout << "DFS travel -"  ; DFS('a', S);
	cout << endl;
	cout << "BFS travel -"  ; BFS('a', Q);
	return 0;
}
