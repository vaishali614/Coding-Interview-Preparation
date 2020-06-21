/** 2. Starting point of a loop in a Linked List **/

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

Node *detectCycle(Node *head) {
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            while(slow != head){
                slow = slow -> next;
                head = head -> next;
            }
            return slow;
        }
    }
    return NULL;
}

Node* takeInput(ll n, ll pos){
    ll data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;
    Node* cycle = NULL;
    if(pos == 0){
        cycle = head;
    }
    for(ll i = 1; i < n; i++){
        ll data;
        cin >> data;
        Node* curr = new Node(data);
        if(pos == i)
            cycle = curr;
        tail->next = curr;
        tail = tail->next;
    }
    tail->next = cycle;
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
    
    ll pos;
    cin >> pos;

    ll n;
    cin >> n;

    Node* head = takeInput(n, pos);

    Node* node = detectCycle(head);
    if(node) cout << "It has a cyle at index " << pos << "!\n";
    else cout << "It doesn't have a cycle!\n";

    return 0;
}
