#include <bits/stdc++.h>
map<int,int> mp;
TreeNode<int>* fun(vector<int> in, vector<int> ps,int lp,int hp,int li,int hi){
     if(lp>hp || li>hi) return nullptr;
     int mi=mp[ps[hp]];
     int el=mi-li,er=hi-mi;
     TreeNode<int> *node=new TreeNode(ps[hp]);
     node->left=fun(in,ps,lp,lp+el-1,li,mi-1);
     node->right=fun(in,ps,lp+el,lp+el+er-1,mi+1,hi);
     return node;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& ps, vector<int>& in){
	int n=in.size();
     for(int i=0;i<n;++i){
          mp[in[i]]=i;
     }
     return fun(in,ps,0,n-1,0,n-1);
}
