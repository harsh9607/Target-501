// GFG - nextgentowers try
//  Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution {
public:
    int maxTowers(int N, int M, vector<vector<int>> connections, int X){
    // Adjacency  list
    map<int , vector<int>> Adj_list ; 
    set<int> Visited;
    
    for(auto it : connections)
    {
        
        Adj_list[it[0]].push_back(it[1]) ;
        Adj_list[it[1]].push_back(it[0]) ;
    }
    
    
    vector<int>Ans ; 
    int node_ctr=0 ; 
    queue<int> Q ;
    for(auto x  : Adj_list)
    {
         
        if(Visited.find(x.first) == Visited.end()){
            
        BFS(x.first,Q ,node_ctr, Visited,Adj_list );
        Ans.push_back(node_ctr) ;
        node_ctr =0; 
        }
        
    }
      
    sort(Ans.begin() , Ans.end() , greater<int>());  
    int dummy = 0 ; 
    for(int val : Ans)
    {
        if(dummy + val <=X)
        {
            dummy += val ; 
        }
        
    }
    
     
         return dummy;   
    }
    
    // Func 
    bool in_Queue(queue<int> q , int x)
    {
        bool ans = false ; 
        while(!q.empty())
        {
            if(q.front()==x)
            {
                ans = true; 
                break;
            }
            q.pop();
        }
        
        return ans; 
    }
    
    //Func 
   void BFS(int source , queue<int>& Q ,int&node_ctr , set<int>&Visited ,  map<int , vector<int>>& Adj_list )
    {
        if(Q.empty())
        {
            Q.push(source); 
        }
        
        int temp = Q.front(); 
       // cout<<"Visiting Node : "<<temp<<endl;
        Visited.insert(temp);
        node_ctr++;
        Q.pop();
        
        for(auto it : Adj_list[temp])
        {
            
            if(Visited.find(it)==Visited.end() && (!in_Queue(Q,it)) )
            {
                Q.push(it);
            }
        }
        
        if(!Q.empty())
        BFS(Q.front() , Q , node_ctr , Visited , Adj_list); 
        
    }
    
    
};

// { Driver Code Starts.

int main(){
    int T;
    
        
        int N=7, M=2, X=5;
        
        vector<vector<int>> connections =   {  {0,1}, {3,2} , {2,4} , {4,5} , {6,6} }  ;
        
        Solution obj;
        cout << obj.maxTowers(N, M, connections, X) << "\n";
    
}
  // } Driver Code Ends
