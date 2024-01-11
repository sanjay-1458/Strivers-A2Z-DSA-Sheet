

bool fun(TreeNode<int> *root, vector<int>& p, int x){
    if(!root) return false;
    p.push_back(root->data); 
    if(root->data==x){
        return true;
    }
    if(fun(root->left,p,x) || fun(root->right,p,x)) return true;
    p.pop_back();
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	vector<int> p1,p2;
    fun(root,p1,x);
    fun(root,p2,y);
    int val=root->data;
    for(int i=0;i<min(p1.size(),p2.size());++i){
        if(p1[i]==p2[i]){
            val=p1[i];
        }
        else{
            break;
        }
    }
    return val;
}
