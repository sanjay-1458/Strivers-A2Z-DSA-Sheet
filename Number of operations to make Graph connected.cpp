Number of operations to make Graph connected.class DisjointSet{
    vector<int> rank,size,parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
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
    void unoinByRank(int u,int v){
        int ultimate_u=findUParent(u);
        int ultimate_v=findUParent(v);
        if(ultimate_u==ultimate_v){
            return;
        }
        if(rank[ultimate_u]<rank[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
        }
        else if(rank[ultimate_v]<rank[ultimate_u]){
            parent[ultimate_v]=ultimate_u;
        }
        else{
            parent[ultimate_v]=ultimate_u;
            rank[ultimate_u]++;
        }
    }
    void unoinBySize(int u,int v){
        int ultimate_u=findUParent(u);
        int ultimate_v=findUParent(v);
        if(ultimate_u==ultimate_v){
            return;
        }
        if(size[ultimate_u]<size[ultimate_v]){
            parent[ultimate_u]=ultimate_v;
            size[ultimate_v]+=size[ultimate_u];
        }
        else{
            parent[ultimate_v]=ultimate_u;
            size[ultimate_u]+=size[ultimate_v];
        }
    }
    int count(int n){
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};


int makeGraphConnected(int n, vector < pair < int,int > > arr, int m) 
{
	DisjointSet ds(n);
	for(int i=0;i<arr.size();++i){
		ds.unoinBySize(arr[i].second,arr[i].first);
		ds.unoinBySize(arr[i].first,arr[i].second);
	}
	int cc=ds.count(n);
	int rem=arr.size()-(n-cc);
	if(rem<cc-1){
		return -1;
	}
	return cc-1;    
}
