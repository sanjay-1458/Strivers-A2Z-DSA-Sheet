#include<bits/stdc++.h>
int missingK(vector < int > vec, int n, int k) {
    if(vec[0]>k) return k;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int diff=vec[mid]-mid-1;
        if(diff<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    int pos=high,val=0;
    int miss=vec[pos]-pos-1;
    int next=k-miss;
    val=vec[pos]+next;
    return val;
}
