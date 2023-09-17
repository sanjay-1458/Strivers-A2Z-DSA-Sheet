vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int z=-1,N=-1;
    for(int i=0;i<n;++i){
        if(a[i]==0){
            z=i;
            break;
        }
    }
    for(int i=z+1;i<n;++i){
        if(a[i]!=0){
            N=i;
            break;
        }
    }
    if(z==-1){
        return a;
    }
    while(N<n){
        if(a[N]!=0){
            swap(a[z],a[N]);
            z++;
        }
        N++;
    }
    return a;
}
