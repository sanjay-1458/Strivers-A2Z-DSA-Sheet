int fun(int mid,int n){
  long long ans=1;
  for(int i=0;i<n;++i){
    if(ans>INT_MAX/mid){
      return INT_MAX;
    }
    ans*=mid;
  }
  return ans;
}


int NthRoot(int n, int m) {
  int low=1,high=m;
  int ans=-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    int val=fun(mid,n);
    if(val==m){
      return mid;
    }
    else if(val>m){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return -1;
}
