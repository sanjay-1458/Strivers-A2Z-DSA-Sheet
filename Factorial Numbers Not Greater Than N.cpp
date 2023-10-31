long long fact(long long n){
    if(n==0) return 1;
    return n*fact(n-1);
}

vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> ans;
    for(int i=1;i<=n;++i){
        long long x=fact(i);
        if(x>n) break;
        ans.push_back(x);
    }
    return ans;
}
