/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(head==nullptr){
        head=new Node(k);
        return head;
    }
    Node *tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=new Node(k,tail,nullptr);
    return head;
}
