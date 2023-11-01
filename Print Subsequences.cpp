string fun(int i,string arr,int limit){
    int mask=1;
    int ind=arr.size()-1;
    string ans="";
    while(mask<=limit){
        if(mask&i){
            ans+=arr[ind];
        }
        ind--;
        mask=mask<<1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    int limit=pow(2,s.size())-1;
    for(int i=0;i<=limit;++i){
        ans.push_back(fun(i,s,limit));
    }
    return ans;
}
