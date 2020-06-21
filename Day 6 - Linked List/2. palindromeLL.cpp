/** 2. Palindrome Linked List **/

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

Node* reverseList(Node* head){
        if(head == NULL)
            return NULL;
        Node* prev = NULL, *curr = head, *nxt = head->next;
        while(nxt != NULL){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        return curr;
    }

bool checkPalindrome(Node* head){
    if(head == NULL || head->next == NULL) 
        return true;
    
    Node* slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* mid = slow->next;
    slow->next = NULL;
    slow = reverseList(mid);
    bool isPalin = true;
    while(slow && head){
        if(slow->data != head->data){
            isPalin = false;
            break;
        }
        slow = slow->next;
        head = head->next;
    }
    
    if(isPalin) return true;
    else return false;
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

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    Node* head = takeInput(n);
    bool flag = checkPalindrome(head);

    if(flag) cout << "Its a Palindrome!\n";
    else cout << "Its not a Palindrome!\n";

    return 0;
}
