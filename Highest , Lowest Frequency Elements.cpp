vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    map<int,int> mp;
    for(auto i:v){
        mp[i]++;
    }
    int maxi=0,mini=INT_MAX;
    for(auto x:mp){
        if(x.second>maxi){
            maxi=x.second;
        }
        if(x.second<mini){
            mini=x.second;
        }
    }
    int a=0,b=0;
    for(auto x:mp){
        if(maxi==x.second && a==0){
            a=x.first;
        }
        if(mini==x.second && b==0){
            b=x.first;
        }
    }
    return {a,b};
}
