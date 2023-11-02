void fun(int ind,int sum,vector<int> vec,vector<vector<int>>&res,vector<int>&arr,int k){
    if(sum==k){
        sort(vec.begin(),vec.end());
        res.push_back(vec);
        return;
    }
    if(sum>k){
        return;
    }
    if(ind>=arr.size()){
        return;
    }
    fun(ind+1,sum,vec,res,arr,k);
    sum+=arr[ind];
    vec.push_back(arr[ind]);
    fun(ind,sum,vec,res,arr,k);
}


void fun(int ind,int sum,vector<int> vec,vector<vector<int>>&res,vector<int>&arr,int k){
    if(sum==k){
        sort(vec.begin(),vec.end());
        res.push_back(vec);
        return;
    }
    if(sum>k){
        return;
    }
    if(ind>=arr.size()){
        return;
    }
    if(arr[ind]<=k){
        fun(ind+1,sum,vec,res,arr,k);
        sum+=arr[ind];
        vec.push_back(arr[ind]);
        fun(ind,sum,vec,res,arr,k);
    }
    else{
        fun(ind+1,sum,vec,res,arr,k);
    }
}

void fun(int ind,int sum,vector<int> vec,vector<vector<int>>&res,vector<int>&arr,int k){
    if(sum==k){
        sort(vec.begin(),vec.end());
        res.push_back(vec);
        return;
    }
    if(sum>k){
        return;
    }
    if(ind>=arr.size()){
        return;
    }
    fun(ind+1,sum,vec,res,arr,k);
    sum+=arr[ind];
    vec.push_back(arr[ind]);
    fun(ind,sum,vec,res,arr,k);
}



vector<vector<int>> combSum(vector<int> &arr, int k)
{
    vector<vector<int>> res;
    fun(0,0,{},res,arr,k);
    sort(res.begin(),res.end());
    return res;
}
