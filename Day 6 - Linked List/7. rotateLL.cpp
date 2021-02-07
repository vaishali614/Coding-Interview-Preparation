/** 6. Rotate Linked List **/
/*
1. Remove last node and insert in the beginning k times. // T: O(K * N), S: O(1)
2. If (k >= len), then k = k % len. Convert the LL to a circular LL, then move len - k nodes ahead and add NULL to the last node. // T: O(N) + O(N - (N % k)) ~ O(N), S: O(1) 
*/

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

Node* rotateRight(Node* head, ll k) {
    if(!head || !head->next) 
        return head;
    
    ll len = 1;
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
        len++;
    }
    
    temp->next = head; // converting to cicrcular LL to avoid the commented part below (line 48 to line 53)
    
    k %= len;
    if (!k)
        return head;
    
    temp = head;
    ll j = len - k;
    for(ll i = 0; i < j - 1; i++){
        temp = temp->next;
    }
    
    Node* newHead = temp->next;
    temp->next = NULL;
//     Node* tail = newHead;
//     temp->next = NULL;
//     while(tail && tail->next){
//         tail = tail->next;
//     }
//     if(tail) tail->next = head;
    return newHead;
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

    ll k;
    cin >> k;

    head = rotateRight(head, k);
    printLL(head);

    return 0;
}
