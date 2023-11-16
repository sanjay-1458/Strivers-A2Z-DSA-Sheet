string getAlienLanguage(vector<string> &dict, int k)
{
    vector<int> adj[k];
    vector<int> indeg(k,0);
    string s="";
    for(int i=0;i<dict.size()-1;++i){
        string s1=dict[i],s2=dict[i+1];
        int j=0,k=0;
        while(j<s1.size() && k<s2.size()){
            if(s1[j]==s2[k]){
                j++;
                k++;
            }
            else{
                adj[s1[j]-'a'].push_back(s2[k]-'a');
                indeg[s2[k]-'a']++;
                break;
            }
        }
    }
    queue<int> q;
    for(int i=0;i<k;++i){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        s+='a'+node;
        for(auto x:adj[node]){
            if(indeg[x]==1){
                q.push(x);
            }
            indeg[x]--;
        }
    }
    return s;

}
