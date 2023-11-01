#include <bits/stdc++.h>
void fun(int n,int n1,int n2,string arr,set<string>&res){
    if(n1>=n && n2>=n){
        res.insert(arr);
        return;
    }
    if(arr.size()==0){
        fun(n,n1+1,n2,arr+'(',res);
    }
    if(n1>=n && n2<n && n1>n2 && !arr.empty()){
        fun(n,n1,n2+1,arr+')',res);
    }
    if(n2>=n && n1<n){
        fun(n,n1+1,n2,arr+'(',res);
    }
    if(n1<n && n2<n){
        if(n1>n2 && !arr.empty())
            fun(n,n1,n2+1,arr+')',res);
        fun(n,n1+1,n2,arr+'(',res);
    }
}


vector<string> validParenthesis(int n){
    set<string> res;
    fun(n,0,0,"",res);
    vector<string> vec;
    for(auto x:res){
        vec.push_back(x);
    }
    return vec;
}
