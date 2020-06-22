/** Queue Implementation using Linked List **/

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

class Queue{
    Node* front, *rear;
    ll size;

    public:
    
    Queue(){
        front = rear = NULL;
        size = 0;
    }

    void push(ll data){
        Node* curr = new Node(data);
        if(empty()){
            front = rear = curr;
            size++;
            return;
        }
        rear->next = curr;
        rear = curr;
        size++;
    }

    void pop(){
        if(front == NULL || rear == NULL)
            return;
        Node* temp = front;
        if(temp->next) 
            temp = temp->next;
        front = temp;
        size--;
    }

    ll peek(){
        if(front == NULL || rear == NULL){
            return 0;
        } else {
            return front->data;
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
    Queue q;
    for(ll i = 0; i < n; i++){
        ll data;
        cin >> data;
        q.push(data);
    }

    cout << q.getSize() << "\n";

    while(!q.empty()){
        ll val = q.peek();
        cout << val << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
