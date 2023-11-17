int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int matrix[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i!=j){
                matrix[i][j]=1e9;
            }
            else{
                matrix[i][j]=0;
            }
        }
    }
    for(int i=0;i<m;++i){
        int u=edges[i][0]-1;
        int v=edges[i][1]-1;
        int wt=edges[i][2];
        matrix[u][v]=wt;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][k]!=1e9 && matrix[k][j]!=1e9){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
    }
    return matrix[src-1][dest-1];
}
