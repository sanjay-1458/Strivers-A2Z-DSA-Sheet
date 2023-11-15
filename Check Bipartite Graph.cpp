#include<bits/stdc++.h>

bool isGraphBirpatite1(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<int> adj[n];
	queue<int> q;
	vector<int> color(n,0);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	color[0]=1;
	q.push(1);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		int clr=color[node];
		for(auto x:adj[node]){
			if(color[x]==0){
				if(clr==1){
					color[x]=2;
				}
				else{
					color[x]=1;
				}
				q.push(x);
			}
			else if(color[x]==clr){
				return false;
			}
		}
	}
	return true;
}

bool dfs(int node,vector<int>&color,vector<int> adj[],int parent){
	if(parent==-1 || color[parent]==2){
		color[node]=1;
	}
	else{
		color[node]=2;
	}
	for(auto x:adj[node]){
		if(color[x]==0){
			if(dfs(x,color,adj,node)==false){
				return false;
			}
		}
		else if(color[x]==color[node]){
			return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges){
	int n=edges.size();
	vector<int> adj[n];
	vector<int> color(n,0);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for(int i=0;i<n;++i){
		if(color[i]==0){
			if(dfs(i,color,adj,-1)==false){
				return false;
			}
		}
	}
	
	return true;
}
