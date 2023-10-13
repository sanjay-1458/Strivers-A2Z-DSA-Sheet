bool fun(int i,int j,vector<vector<int>>&arr){
    int n=arr.size(),m=arr[0].size();
    int n1=-1,n2=-1,n3=-1,n4=-1;
    if(i-1>=0) n1=arr[i-1][j];
    if(j+1<m) n2=arr[i][j+1];
    if(i+1<n) n3=arr[i+1][j];
    if(j-1>=0) n4=arr[i][j-1];
    if(arr[i][j]>n1 && arr[i][j]>n2 && arr[i][j]>n3 && arr[i][j]>n4){
        return true;
    }
    return false;
}
vector<int> fun1(int i,int j,vector<vector<int>>&arr){
    int n=arr.size(),m=arr[0].size();
    int n1=-1,n2=-1,n3=-1,n4=-1;
    if(i-1>=0) n1=arr[i-1][j];
    if(j+1<m) n2=arr[i][j+1];
    if(i+1<n) n3=arr[i+1][j];
    if(j-1>=0) n4=arr[i][j-1];
    if(arr[i][j]<n1) return {i-1,j};
    if(arr[i][j]<n2) return {i,j+1};
    if(arr[i][j]<n3) return {i+1,j};
    if(arr[i][j]<n4) return {i,j-1};
    return {-1,-1};
}
vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n=mat.size(),m=mat[0].size();
    int row=0,col=0;
    while(true){
        if(fun(row,col,mat)==true){
            return {row,col};
        }
        vector<int> v=fun1(row,col,mat);
        row=v[0];
        col=v[1];
    }
    return {-1,-1};   
}
