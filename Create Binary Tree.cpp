
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
Node* createTree(vector<int>&arr){
   Node *root=new Node();
   root->data=arr[0];
   queue<pair<Node*,int>> q;
   q.push({root,0});
   while(!q.empty()){
       Node* node=q.front().first;
       int ind=q.front().second;
       q.pop();
       int left=2*ind+1;
       int right=2*ind+2;
       if(left>=7) break;
       Node *l=new Node();
       Node *r=new Node();
       l->data=arr[left];
       r->data=arr[right];
       node->left=l;
       node->right=r;
       q.push({l,left});
       q.push({r,right});
   }
   return root;
}
