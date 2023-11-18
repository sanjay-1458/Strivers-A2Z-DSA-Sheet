#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
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
        if(ultimate_v==ultimate_u){
            return;
        }
        if(rank[v]>rank[u]){
            parent[ultimate_u]=ultimate_v;
        }
        else if(rank[u]>rank[v]){
            parent[ultimate_v]=ultimate_u;
        }
        else{
            parent[ultimate_v]=ultimate_u;
            rank[ultimate_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ultimate_u=findUParent(u);
        int ultimate_v=findUParent(v);
        if(ultimate_v==ultimate_u){
            return;
        }
        if(size[ultimate_u]<size[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
            size[ultimate_v]+=size[ultimate_u];
        }
        else if(size[ultimate_v]<size[ultimate_u]){
            parent[ultimate_v]=ultimate_u;
            size[ultimate_u]+=size[ultimate_v];
        }
        else{
            parent[ultimate_v]=ultimate_u;
            size[ultimate_u]+=size[ultimate_v];
        }
    }
};


int main(){
    
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    
    
    if(ds.findUParent(3)==ds.findUParent(7)){
        cout<<"Same\n";
    }
    else{
        cout<<"Different\n";
    }
    ds.unionByRank(3,7);
    return 0;
}
