/** 1. Merge two sorted Linked List **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

class Node{
    public:
    ll data;
    Node* next;
    Node(ll data){
        this->data = data;
        this->next = NULL;
    }
};

Node* merge(Node* l1, Node* l2){
    Node* lh = new Node(0);
    Node* lt = new Node(0);
    
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    
    if(l1->data <= l2->data){
        lh = l1;
        lt = l1;
        l1 = l1->next;
    } else if(l1 && l2 && l1->data > l2->data) {
        lh = l2;
        lt = l2;
        l2 = l2->next;
    }
    
    while(l1 && l2){
        if(l1->data < l2->data){
            lt->next = l1;
            l1 = l1->next;
        } else {
            lt->next = l2;
            l2 = l2->next;
        }
        lt = lt->next;   
    }
    
    if(l1)
        lt->next = l1;
    if(l2)
        lt->next = l2;
    
    return lh;
}

Node* takeInput(ll n){
    ll data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;
    for(ll i = 1; i < n; i++){
        ll data;
        cin >> data;
        Node* curr = new Node(data);
        tail->next = curr;
        tail = tail->next;
    }
    tail->next = NULL;
    return head;
}

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n1;
    cin >> n1;
    Node* l1 = takeInput(n1);

    ll n2;
    cin >> n2;
    Node* l2 = takeInput(n2);

    Node* l = merge(l1, l2);
    printLL(l);
   
    return 0;
}
