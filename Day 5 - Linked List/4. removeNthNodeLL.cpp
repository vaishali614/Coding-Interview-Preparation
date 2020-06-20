/** 4. Remove nth node from end of list **/

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

Node* removeNthNode(Node* head, ll n){
    ll nodeCount = 0;
    Node* temp = head;
    while(temp != NULL){
        nodeCount++;
        temp = temp->next;
    }
    
    if(nodeCount == n)
        return head->next;
    
    ll x = nodeCount - n;
    temp = head;
    for(ll i = 0; i < (x - 1) && temp != NULL; i++){
        temp = temp->next;
    }
    
    if(temp->next != NULL)
        temp->next = temp->next->next;
    return head;
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

    ll pos;
    cin >> pos;

    head = removeNthNode(head, pos);
    printLL(head);

    return 0;
}
