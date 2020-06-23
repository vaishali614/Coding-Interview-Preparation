/** Min Stack **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

class Node {
    public:
    int data;
    int minVal;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }  
};

class MinStack {
    Node* head;
    int size;
    public:
    
    MinStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int data) {
        Node* newNode = new Node(data);
        if(head == NULL){
            newNode->minVal = data;
        } else {
            newNode->minVal = min(data, head->minVal);
        }
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    ll getSize(){
        return size;
    }

    void pop() {
        head = head->next;
        size--;
    }
    
    int top() {
        int top = head->data;
        return top;
    }
    
    int getMin() {
        return head->minVal;
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    MinStack s;

    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll data;
        cin >> data;
        s.push(data);
    }

    cout << "Min = " << s.getMin() << "\n";

    while(s.getSize()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
