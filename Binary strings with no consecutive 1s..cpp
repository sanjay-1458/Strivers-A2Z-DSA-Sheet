void fun(int n,string arr,int ind,vector<string>&res){
    if(ind>=n){
        res.push_back(arr);
        return;
    }
    if(arr.empty() || arr[ind-1]=='0'){
        arr.push_back('1');
        fun(n,arr,ind+1,res);
        arr.pop_back();
        arr.push_back('0');
        fun(n,arr,ind+1,res);
    }
    else{
        arr.push_back('0');
        fun(n,arr,ind+1,res);
    }
}

vector<string> generateString(int n) {
    vector<string> res;
    string w="";
    fun(n,w,0,res);
    reverse(res.begin(),res.end());
    return res;
}
