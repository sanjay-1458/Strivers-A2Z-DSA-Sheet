#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1];
  queue<int> q;
  vector<int> indeg(n+1,0);
  for(int i=0;i<edges.size();++i){
    adj[edges[i].first].push_back(edges[i].second);
    indeg[edges[i].second]++;
  }
  for(int i=1;i<n+1;++i){
    if(indeg[i]==0){
      q.push(i);
    }
  }
  vector<int> ans;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(auto x:adj[node]){
      if(indeg[x]==1){
        q.push(x);
      }
      indeg[x]--;
    }
  }
  if(ans.size()==n){
    return 0;
  }
  else{
    return 1;
  }
}
