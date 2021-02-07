/** 1. Intersection of two Linked Lists **/
/*
1. Brute Force: Compare every node of both the LL // T: O(N * M), S: O(1)
2. Use hashmap to store reference of nodes in one LL, then traverse the second LL and search if the same reference is present in the hashmap or not. // T: O(N + M), S: O(N)
3. Find lengths of both LL. Then find the diff of their lengths. Move the longer LL diff steps ahead. Now, both the LLs need to cover same no. of steps to reach the common node. // T: O(M) + O(M - N) + O(N) = O(2 * M), S: O(1)
4. [BEST] - Traverse both LLs simultaneously. If anyone of them reaches NULL, take it to the start of other LL. At one point both of them will collide because the LL that'll reach NULL first, the other LL will have the extra part to be travelled. //O(2 * M), S: O(1)
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
    if(headA == NULL || headB == NULL)
        return NULL;
    
    Node* a = headA, *b = headB;
    while(a != b){
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
