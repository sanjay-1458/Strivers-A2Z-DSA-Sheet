string fun(int ind1,int ind2,string &s,string &t,vector<vector<string>>&dp){
	if(ind1==0 ||ind2==0) return "";
	if(dp[ind1][ind2]!="") return dp[ind1][ind2];
	if(s[ind1-1]==t[ind2-1]){
		string e=fun(ind1-1,ind2-1,s,t,dp);
		return dp[ind1][ind2]=s[ind1-1]+e;
	}
	else{
		string a=fun(ind1-1,ind2,s,t,dp);
		string b=fun(ind1,ind2-1,s,t,dp);
		if(a.size()>b.size()){
			dp[ind1][ind2]=a;
		}
		else{
			dp[ind1][ind2]=b;
		}
		return dp[ind1][ind2];
	}
}

string findLCS1(int n, int m,string &s, string &t){
	
	vector<vector<string>> dp(n+1,vector<string>(m+1,""));
	for(int j=0;j<=m;++j){
		dp[0][j]="";
	}
	for(int i=0;i<=n;++i){
		dp[i][0]="";
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i-1]==t[j-1]){
				dp[i][j]=s[i-1]+dp[i-1][j-1];
			}
			else{
				string a=dp[i-1][j];
				string b=dp[i][j-1];
				if(a.size()>b.size()){
					dp[i][j]=a;
				}
				else{
					dp[i][j]=b;
				}
			}
		}
	}
	string ans=dp[n][m];
	reverse(ans.begin(),ans.end());
	return ans;
}
string findLCS(int n, int m,string &s, string &t){
	
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int j=0;j<=m;++j){
		dp[0][j]=0;
	}
	for(int i=0;i<=n;++i){
		dp[i][0]=0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string ans="";
	int i=n,j=m;
	while(i>0 && j>0){
		if(s[i-1]==t[j-1]){
			ans+=s[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
