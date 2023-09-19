int longestSuccessiveElements(vector<int>&a) {
        int res=0,n=a.size();
        if(n==0) return res;
        vector<int> v;
        map<int,int> mp;
        for(int i=0;i<n;++i){
            mp[a[i]]++;
        }
        for(auto e:mp){
            v.push_back(e.first);
        }
        int cnt=0;
        for(int i=0;i<v.size()-1;++i){
            if(v[i+1]-v[i]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            res=max(cnt,res);
        }
        res+=1;
        return res;
}
