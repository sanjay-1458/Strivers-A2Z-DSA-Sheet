#include <bits/stdc++.h>
using namespace std;

void fun(vector<int>&arr, int k,int sum,vector<int> v,int ind){
    if(sum==k){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(ind>=arr.size() || sum>k){
        return;
    }
    sum+=arr[ind];
    v.push_back(arr[ind]);
    fun(arr,k,sum,v,ind+1);
    sum-=arr[ind];
    v.pop_back();
    fun(arr,k,sum,v,ind+1);
}

int main()
{
    vector<int> arr={3,1,5,2,0,9,8,0,4,5};
    int k=9;
    fun(arr,k,0,{},0);
}
