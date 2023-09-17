#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n=a.size(),m=b.size();
    vector<int> temp;
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]<b[j] ){
          if (temp.empty() || temp.back() != a[i]) {
            temp.push_back(a[i]);
          }
            i++;
        }
        else if(b[j]<a[i] ){
            if (temp.empty() || temp.back()!=b[j]){
            temp.push_back(b[j]);
            }
            j++;
        }
        else if(a[i]==b[j] ){
            if (temp.empty() || temp.back() != a[i]) {
            temp.push_back(a[i]);
            }
            i++;
        }
    }
    while(i<n){
        if(temp.empty() || temp.back()!=a[i]){
            temp.push_back(a[i]);
        }
        i++;
    }
    while(j<m){
        if(temp.empty() || temp.back()!=b[j]){
            temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}
