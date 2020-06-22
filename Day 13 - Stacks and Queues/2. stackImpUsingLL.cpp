/** Stack Implementation using Linked List **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

class Node {
    public :
    int data;
    Node *next;
    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

class Stack{
    Node* head;
    ll size;

    public:
    
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(ll data){
        Node* curr = new Node(data);
        curr->next = head;
        head = curr;
        size++;
    }

    void pop(){
        if(head == NULL)
            return;
        head = head->next;
        size--;
    }

    ll peek(){
        if(head == NULL){
            return 0;
        } else {
            return head->data;
        }
    }

    ll getSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    Stack s;
    for(ll i = 0; i < n; i++){
        ll data;
        cin >> data;
        s.push(data);
    }

    cout << s.getSize() << "\n";

    while(!s.empty()){
        ll val = s.peek();
        cout << val << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
