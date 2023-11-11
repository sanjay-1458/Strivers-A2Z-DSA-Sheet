#include<bits/stdc++.h>

int fun(int ind1,int ind2, string &s,string&t){
	if(ind1<0 ||ind2<0){
		return 0;
	}
	if(ind1==0 && ind2==0){
		if(s[ind1]==t[ind2]){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(ind1==0 && ind2!=0){
		for(int i=0;i<=ind2;++i){
			if(s[ind1]==t[i]){
				return 1;
			}
		}
		return 0;
	}
		if(ind2==0 && ind1!=0){
			for(int i=0;i<=ind1;++i){
				if(s[i]==t[ind2]){
					return 1;
				}
			}
			return 0;
		}
	
	if(s[ind1]==t[ind2]){
		return 1+fun(ind1-1,ind2-1,s,t);
	}
	else{
		int first=fun(ind1-1,ind2,s,t);
		int second=fun(ind1,ind2-1,s,t);
		return max(first,second);
	}
}

int lcs(string s, string t)
{
	// return fun(s.size()-1,t.size()-1,s,t);

	int ind1=s.size()-1;
	int ind2=t.size()-1;
	if(s.size()==0 || t.size()==0) return 0;
	vector<vector<int>> dp(ind1+1,vector<int>(ind2+1,0));
	for(int i=0;i<=ind1;++i){
		for(int j=0;j<=ind2;++j){
			if(i==0 && j==0){
				if(s[i]==t[j]){
					dp[i][j]=1;
				}
			}
			else if(i==0 && j!=0){
				for(int l=0;l<=j;++l){
					if(s[i]==t[l]){
						dp[i][j]= 1;
					}
				}
			}
			else if(j==0 && i!=0){
				for(int l=0;l<=i;++l){
					if(s[l]==t[j]){
						dp[i][j]=1;
					}
				}
			}
			else if(s[i]==t[j]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				int first=dp[i-1][j];
				int second=dp[i][j-1];
				dp[i][j]=max(first,second);
			}
		}
	}
	return dp[ind1][ind2];
}
