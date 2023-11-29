#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




int fun(vector<int>&arr,int l,int h){
    if(l<h){
        int mid=(l+h)>>1;
        int left=fun(arr,l,mid);
        int right=fun(arr,mid+1,h);
        return left+right;
    }
    else{
        return arr[l];
    }
}

void solve()
{
    vector<int> arr={1,2,3,4,5};
    cout<<fun(arr,0,arr.size()-1);
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
