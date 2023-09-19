vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> res;
    res.push_back({1});
    res.push_back({1,1});
    vector<int> v={1,2,1};
    res.push_back(v);
    if(N<=3){
        res.resize(N);
        return res;
    }
    N=N-3;
    while(N--){
        vector<int> w;
        w.push_back(1);
        for(int i=0;i<v.size()-1;++i){
            int sum=v[i]+v[i+1];
            w.push_back(sum);
        }
        w.push_back(1);
        res.push_back(w);
        v=w;
    }
    return res;
}
