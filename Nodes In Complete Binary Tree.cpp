#include <bits/stdc++.h> 


int left(BinaryTreeNode<int> * node){
    if(node==nullptr) return 0;
    return 1+left(node->left);
}

int right(BinaryTreeNode<int> * node){
    if(node==nullptr) return 0;
    return 1+right(node->right);
}

int fun(BinaryTreeNode<int> * node){
    if(node==nullptr) return 0;
    int lh=left(node);
    int rh=right(node);
    if(lh==rh){
        return (1<<lh)-1;
    }
    else{
        return 1+fun(node->left)+fun(node->right);
    }
}

int countNodes(BinaryTreeNode<int> *root) {
    return fun(root);
}
