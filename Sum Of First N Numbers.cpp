long long fun(long long sum,long long n){
    if(n==0) return sum;
    return fun(sum+n,n-1);
}

long long sumFirstN(long long n) {
    return fun(0,n);
}
