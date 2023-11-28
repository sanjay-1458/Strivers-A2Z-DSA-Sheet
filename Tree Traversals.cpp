/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode *node,vector<int>&ans){
    if(node==nullptr){
        return;
    }
    inorder(node->left,ans);
    ans.push_back(node->data);
    inorder(node->right,ans);
}

void preorder(TreeNode *node,vector<int>&ans){
    if(node==nullptr){
        return;
    }
    ans.push_back(node->data);
    preorder(node->left,ans);
    preorder(node->right,ans);
}

void postorder(TreeNode *node,vector<int>&ans){
    if(node==nullptr){
        return;
    }
    postorder(node->left,ans);
    postorder(node->right,ans);
    ans.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    vector<int> v;
    inorder(root, v);
    ans.push_back(v);
    v.clear();
    preorder(root, v);
    ans.push_back(v);
    v.clear();
    postorder(root, v);
    ans.push_back(v);
    return ans;
}
