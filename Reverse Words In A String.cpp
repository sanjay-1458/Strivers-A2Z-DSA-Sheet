#include<bits/stdc++.h>

string reverseString(string &str){
	// Write your code here.
	stack<string> s;
	int i=0;
	string w="";
	while(i<str.size()){
		if(str[i]!=' '){
			w+=str[i];
		}
		else{
			if(w!="")
				s.push(w);
			w="";
		}
		i++;
	}
	s.push(w);
	string ans="";
	while(!s.empty()){
		string x=s.top();
		s.pop();
		if(x!=""){
			x += ' ';
			ans.insert(ans.end(), x.begin(), x.end());
		}
	}
	return ans;
}
