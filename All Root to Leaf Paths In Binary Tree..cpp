
bool leaf(BinaryTreeNode<int> *node){
    if(node->left==NULL && node->right==NULL) return true;
    else return false;
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<string> ans;
    queue<pair<BinaryTreeNode<int> *,string>> q;
    string w="";
    if(!root){
        return ans;
    }
    w+=to_string(root->data);
    w+=" ";
    q.push({root,w});
    while(!q.empty()){
        BinaryTreeNode<int> *node=q.front().first;
        string a=q.front().second;
        q.pop();
        if(leaf(node)){
            ans.push_back(a);
        }
        if(node->left){
            string t=a;
            t+=to_string(node->left->data);
            t+=" ";
            q.push({node->left,t});
        }
        if(node->right){
            string t=a;
            t+=to_string(node->right->data);
            t+=" ";
            q.push({node->right,t});
        }
    }
    return ans;
}
