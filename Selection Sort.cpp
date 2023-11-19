#include<bits/stdc++.h>
void selectionSort(vector<int>&arr) {
    // Write your code here.
    int i=0,n=arr.size();
    for(i=0;i<n-1;++i){
        int mini=INT_MAX;int ind=i;
        for(int j=i+1;j<n;++j){
            if(mini>arr[j]){
                mini=arr[j];
                ind=j;
            }
        }
        if(i!=ind)
            swap(arr[i],arr[ind]);
    }
}
