
int fun(Node *node){
    if(!node) return 0;
    if(node->left==NULL && node->right==NULL){
        return node->data;
    }
    int left=fun(node->left);
    int right=fun(node->right);
    if(left==-1 || right==-1) return -1;
    if(left+right==node->data){
        return node->data;
    }
    else{
        return -1;
    }
}

bool isParentSum(Node *root){
    int val=fun(root);
    if(val==-1) return false;
    else return val;
}
