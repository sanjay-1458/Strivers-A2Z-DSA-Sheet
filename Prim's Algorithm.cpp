//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
      int sum=0;
      vector<int> vis(n,0);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
      q.push({0,0});
      while(!q.empty()){
        int node=q.top().second;
        int wt=q.top().first;
        q.pop();
        if(vis[node]){
          continue;
        }
        sum+=wt;
        vis[node]=1;
        for(auto x:adj[node]){
          if(!vis[x[0]])
            q.push({x[1],x[0]});
        }
      }
      return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
