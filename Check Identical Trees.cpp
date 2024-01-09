
bool fun(BinaryTreeNode<int>* node1, BinaryTreeNode<int>* node2){
    if(node1==nullptr || node2==nullptr){
        if(node1==nullptr && node2==nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    if(node1->data!=node2->data) return false;
    bool left=fun(node1->left,node2->left);
    bool right=fun(node1->right,node2->right);
    return (left && right);
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    return fun(root1,root2);
}
