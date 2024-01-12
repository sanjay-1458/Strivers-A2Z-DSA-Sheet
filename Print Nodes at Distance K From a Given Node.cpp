
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k) {
   map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp;
   queue<BinaryTreeNode<int>*> q;
   map<BinaryTreeNode<int>*,bool> vis; 
   mp[root]=nullptr;
   q.push(root);
   while(!q.empty()){
       BinaryTreeNode<int>* node=q.front();
       q.pop();
       if(node->left){
           q.push(node->left);
           mp[node->left]=node;
       }
       if(node->right){
           q.push(node->right);
           mp[node->right]=node;
       }
       vis[node]=false;
   }
   vector<BinaryTreeNode<int>*> v;
   vis[target]=true;
   queue<pair<BinaryTreeNode<int>*,int>> qp;
   qp.push({target,0});
   while(!qp.empty()){
       BinaryTreeNode<int>* node=qp.front().first;
       int dis=qp.front().second;
       qp.pop();
       if(dis==k){
           v.push_back(node);
       }
       if(node->left && !vis[node->left]){
           qp.push({node->left,dis+1});
           vis[node->left]=true;
       }
       if(node->right && !vis[node->right]){
           qp.push({node->right,dis+1});
           vis[node->right]=true;
       }
       if(mp[node] && !vis[mp[node]]){
           qp.push({mp[node],dis+1});
           vis[mp[node]]=true;
       }
   }
   return v;
}
