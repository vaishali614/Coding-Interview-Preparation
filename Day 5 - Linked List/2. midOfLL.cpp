/** 2. Middle of Linked List **/

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

Node* findMid(Node* head){
    Node* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
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

    head = findMid(head);
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
