/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node *head=NULL;
    Node *tail=NULL;
    for(int i=0;i<arr.size();++i){
        Node *newNode=NULL;
        newNode=new Node(arr[i]);
        if(tail!=NULL){
            tail->next=newNode;
            tail=tail->next;
        }
        else{
            tail=newNode;
        }
        if(head==NULL){
            head=newNode;
        }
    }
    return head;
}
