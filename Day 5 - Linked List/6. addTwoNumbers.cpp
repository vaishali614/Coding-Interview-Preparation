/** 6. Add two numbers as Linked List **/
/* T : O(max(n1, n2)) & S : O(max(n1, n2)) */

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

Node* addTwoNumbers(Node* l1, Node* l2){
    int carry = 0;
    Node* sum = new Node(0);
    Node* tail = sum;
    while(l1 && l2){
        int s = l1->data + l2->data + carry;
        tail->next = new Node(s % 10);
        carry = s / 10;
        tail = tail->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1){
        int s = l1->data + carry;
        tail->next = new Node(s % 10);
        carry = s / 10;
        tail = tail->next;
        l1 = l1->next;
    }
    
    while(l2){
        int s = l2->data + carry;
        tail->next = new Node(s % 10);
        carry = s / 10;
        tail = tail->next;
        l2 = l2->next;
    }
    
    if(carry)
        tail->next = new Node(carry);
    
    return sum->next;
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

    Node* l = addTwoNumbers(l1, l2);
    printLL(l);    

    return 0;
}
