/** 5. Delete node in Linked List **/

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

void deleteNode(Node* node){
    node->data = node->next->data;
    node->next = node->next->next;
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
    
    ll n;
    cin >> n;
    Node* head = takeInput(n);

    ll del;
    cin >> del;
    Node* node = head;
    while(node->data != del){
        node = node->next;
    }
    deleteNode(node);
    printLL(head);

    return 0;
}
