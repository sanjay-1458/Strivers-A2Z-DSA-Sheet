int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    if(k<vec[0]) return k;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=vec[mid]-mid-1;
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    int miss=vec[high]-high-1;
    int pos=k-miss;
    int val=vec[high]+pos;
    return val;
}
