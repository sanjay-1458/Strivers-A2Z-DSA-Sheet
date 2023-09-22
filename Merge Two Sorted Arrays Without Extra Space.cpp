#include<vector>
#include<algorithm>
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n1=a.size(),n2=b.size();
	while(true){
		int val1=b[0];
		vector<long long>::iterator pos;
		pos=upper_bound(a.begin(),a.end(),val1);
		int ind=pos-a.begin();
		if(ind>=0 && ind<n1){
			int val2=a[n1-1];
			for(int j=n1-1;j>ind;--j){
				a[j]=a[j-1];
			}
			a[ind]=val1;
			pos=lower_bound(b.begin(),b.end(),val2);
			ind=pos-b.begin();
			if(ind==n2) ind--;
			else if(b[ind]!=val2){
				ind--;
			}
			for(int j=0;j<ind;++j){
				b[j]=b[j+1];
			}
			b[ind]=val2;
			
		}
		else{
			break;
		}
	}
	
}
