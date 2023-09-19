vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int n=A.size();
    int c1=0,c2=0;
    if(n==1) return A;
    int ind=-1;
    for(int i=n-1;i>=0;--i){
        if(A[i]<=A[i-1]){
            continue;
        }
        else{
            ind=i-1;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    int pos=-1;
    for(int i=n-1;i>=0;--i){
        if(A[i]>A[ind]){
            pos=i;
            break;
        }
    }
    swap(A[pos],A[ind]);
    sort(A.begin()+1+ind,A.end());
    return A;
}
