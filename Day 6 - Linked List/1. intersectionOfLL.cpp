/** 1. Intersection of two Linked Lists **/

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

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* a = headA, *b = headB;
    while((a && !b) || (!a && b) || (a->data != b->data)){
        a = (a) ? a->next : headB;
        b = (b) ? b->next : headA;
    }
    return a;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n1;
    cin >> n1;
    Node* headA = takeInput(n1);

    ll n2;
    cin >> n2;
    Node* headB = takeInput(n2);

    Node* intersection = getIntersectionNode(headA, headB);
    cout << intersection->data << "\n";

    return 0;
}
