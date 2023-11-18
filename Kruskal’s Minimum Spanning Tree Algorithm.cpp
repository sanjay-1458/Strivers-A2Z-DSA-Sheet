#include<bits/stdc++.h>

class DisjointSet{
	vector<int> rank,parent;
public:
	DisjointSet(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		for(int i=0;i<=n;++i){
			parent[i]=i;
		}
	}
	int findUParent(int node){
		if(node==parent[node]){
			return node;
		}
		return parent[node]=findUParent(parent[node]);
	}
	void unionByRank(int u,int v){
		int ultimate_u=findUParent(u);
		int ultimate_v=findUParent(v);
		if(ultimate_u==ultimate_v){
			return;
		}
		if(rank[ultimate_v]<rank[ultimate_u]){
			parent[ultimate_v]=ultimate_u;
		}
		else if(rank[ultimate_u]<rank[ultimate_v]){
			parent[ultimate_u]=ultimate_v;
		}
		else{
			parent[ultimate_v]=ultimate_u;
			rank[ultimate_u]++;
		}
	}

};


int kruskalMST(int n, vector<vector<int>> &edges)
{

	DisjointSet ds(n+1);
	vector<pair<int,pair<int,int>>> adj;
	for(int i=0;i<edges.size();++i){
		int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
		adj.push_back({wt,{u,v}});
		adj.push_back({wt,{v,u}});
	}
	sort(adj.begin(),adj.end());
	int sum=0;
	for(int i=0;i<adj.size();++i){
		int wt=adj[i].first;
		int u=adj[i].second.first;
		int v=adj[i].second.second;
		if(ds.findUParent(u)==ds.findUParent(v)){
			continue;
		}
		sum+=wt;
		ds.unionByRank(u, v);
	}
	return sum;
}
