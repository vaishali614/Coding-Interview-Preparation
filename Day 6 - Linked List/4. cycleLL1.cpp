/** 4. Linked List Cycle **/
/*
1. Using Hashmap: Insert the complete node in the hashmap while traversing the LL. If any of the nodes, is already present in the hashmap, then it contains a cycle. // T: O(N), S: O(N)
2. Using Slow and Fast pointers: Move slow one step ahead and move fast two steps ahead. If there's a cycle, slow and fast pointers will collide at some point. // T: O(N), S: O(1)
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

bool hasCycle(Node *head) {
    if(head == NULL || head->next == NULL) 
        return false;
    
    Node* slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
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

    bool flag = hasCycle(head);
    if(flag) cout << "It has a cyle!\n";
    else cout << "It doesn't have a cycle!\n";

    return 0;
}
