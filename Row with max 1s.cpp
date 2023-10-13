int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int ans=0,ind=-1;
    for(int i=0;i<n;++i){
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[i][mid]==0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(low==m) continue;
        int ones=m-low;
        if(ans<ones){
            ans=ones;
            ind=i;
        }
    }
    return ind;
}
