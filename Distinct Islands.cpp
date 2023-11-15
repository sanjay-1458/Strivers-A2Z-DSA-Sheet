#include<bits/stdc++.h>


bool check(vector<int> a,vector<int> b){
    if(a.size()!=b.size()) return false;
    int diff=a[0]-b[0];
    for(int i=1;i<a.size();++i){
        if(diff!=a[i]-b[i]){
            return false;
        }
    }
    return true;
}

void dfs(int r,int c,vector<vector<int>>&vis,vector<pair<int,int>>&temp,int n,int m){
    int dr[]={0,-1,0,1};
    int dc[]={-1,0,1,0};
    vis[r][c]=1;
    temp.push_back({r,c});
    for(int k=0;k<4;++k){
        int newr=r+dr[k],newc=c+dc[k];
        if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc]){
            dfs(newr,newc,vis,temp,n,m);
        }
    }
}

int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> lst;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(arr[i][j]==0){
                vis[i][j]=1;
            }
            else{
                lst.push_back({i,j});
            }
        }
    }

    int cp=0;
    vector<vector<int>> ans;
    set<vector<pair<int,int>>> sp;
    for(int i=0;i<lst.size();++i){
        cp++;
        int r=lst[i][0],c=lst[i][1];
        if(!vis[r][c]){
            vector<pair<int,int>> temp;
            dfs(r,c,vis,temp,n,m);
            sort(temp.begin(),temp.end());;
            cp++;
            vector<pair<int,int>> lp;
            for(int a=0;a<temp.size();++a){
                lp.push_back({temp[0].first-temp[a].first,temp[0].second-temp[a].second});
            }
            sp.insert(lp);
            vector<int> s;
        }
    }

    int cnt=0;
    
    
    return sp.size();
}
