int fun(int ind,int n,int val,vector<vector<int>> &arr){
    if(ind==n) return 0;
    if(val==-1){
        int one =arr[ind][0]+fun(ind+1,n,0,arr);
        int two =arr[ind][1]+fun(ind+1,n,1,arr);
        int three =arr[ind][2]+fun(ind+1,n,2,arr);
        return max(one,max(two,three));
    }
    else if(val==0){
        int two =arr[ind][1]+fun(ind+1,n,1,arr);
        int three =arr[ind][2]+fun(ind+1,n,2,arr);
        return max(two,three);
    }
    else if(val==1){
        int one =arr[ind][0]+fun(ind+1,n,0,arr);
        int three =arr[ind][2]+fun(ind+1,n,2,arr);
        return max(one,three);
    }
    else{
        int one =arr[ind][0]+fun(ind+1,n,0,arr);
        int two =arr[ind][1]+fun(ind+1,n,1,arr);
        return max(two,one);
    }
}


int ninjaTraining(int n, vector<vector<int>> &arr)
{
    return fun(0,n,-1,arr);
}



int fun(int days,int last,vector<vector<int>> &arr){
    if(days==0){
        int maxi=0;
        for(int i=0;i<=2;++i){
            if(i!=last){
                maxi=max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    int ans=0;
    for(int i=0;i<=2;++i){
        if(i!=last){
            int points=arr[days][i]+fun(days-1,i,arr);
            ans=max(ans,points);
        }
    }
    return ans;
}


int fun(int days,int last,vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(days==0){
        int maxi=0;
        for(int i=0;i<=2;++i){
            if(i!=last){
                maxi=max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    int ans=0;
    for(int i=0;i<=2;++i){
        if(i!=last){

            int points;
            if(dp[days][i]!=-1){
                points=dp[days][i];
            }
            else{
                dp[days][i]=arr[days][i]+fun(days-1,i,arr,dp);
                points=dp[days][i];
            }
            ans=max(ans,points);
        }
    }
    return ans;
}


int fun(int days,int last,vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(days==0){
        int maxi=0;
        for(int i=0;i<=2;++i){
            if(i!=last){
                maxi=max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    if(dp[days][last]!=-1) return dp[days][last];
    int ans=0;
    for(int i=0;i<=2;++i){
        if(i!=last){

            int points;
            
            points=arr[days][i]+fun(days-1,i,arr,dp);
            
            ans=max(ans,points);
        }
    }
    return dp[days][last]=ans;
}



int ninjaTraining(int n, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][1], max(arr[0][1], arr[0][2]));
    for(int days=1;days<=n-1;++days){
        for(int last=0;last<=3;++last){
            int ans=0;
             for(int i=0;i<=2;++i){
                if(i!=last){

                    int points;
                    
                    points=arr[days][i]+dp[days-1][i];
                    
                    ans=max(ans,points);
                }
            }
            dp[days][last]=ans;
        }
    }
    return dp[n-1][3];
}
