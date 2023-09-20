#include<bits/stdc++.h>
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int cnt1=0,cnt2=0;
	int el1=INT_MIN,el2=INT_MIN;
	for(int i=0;i<v.size();++i){
		if(cnt1==0 && v[i]!=el2){
			cnt1=1;
			el1=v[i];
		}
		else if(cnt2==0 && v[i]!=el1){
			cnt2=1;
			el2=v[i];
		}
		else if(el1==v[i]){
			cnt1++;
		}
		else if(el2==v[i]){
			cnt2++;
		}
		else{
			cnt1--;
			cnt2--;
		}
	}
	cnt1=0;cnt2=0;
	for(int i=0;i<v.size();++i){
		if(v[i]==el1){
			cnt1++;
		}
		else if(v[i]==el2){
			cnt2++;
		}
	}
	vector<int> r;
	if(cnt1>(v.size())/3){
		r.push_back(el1);
	}
	if(cnt2>(v.size())/3){
		r.push_back(el2);
	}
	sort(r.begin(),r.end());
	return r;
}
