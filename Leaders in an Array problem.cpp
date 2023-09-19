vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> v;
    int n=a.size();
    v.push_back(a[n-1]);
    for(int i=n-2;i>=0;--i){
        int check=a[i];
        int flag=-1;
        for(int j=i+1;j<n;++j){
            if(check<=a[j]){
                flag=0;
            }
        }
        if(flag==-1){
            v.push_back(check);
        }
    }
    return v;
}


vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> v;
    int n=a.size();
    v.push_back(a[n-1]);
    int maxi=a[n-1];
    for(int i=n-2;i>=0;--i){
        if(a[i]>maxi){
            v.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }
    return v;
}
