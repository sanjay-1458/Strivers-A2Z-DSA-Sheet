long long pow(long long a,long long b){
  while(b>0){
    long long ans=pow(a,b/2);
    ans=ans*ans;
    if(b%2){
      return ans;
    }
    else{
      return ans*a;
    }
  }
}

int NthRoot(int n, int m) {
  // Write your code here.
  long long ans=-1,low=1,high=m;
  while(low<=high){
    long long mid=low+(high-low)/2;
    if(pow(mid,n)==m){
      ans=mid;
      break;
    }
    else if(pow(mid,n)>m){
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return ans;
}
