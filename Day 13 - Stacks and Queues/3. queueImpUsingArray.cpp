/** Queue Implementation using arrays **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

class Queue{
    ll front, rear, capacity;
    ll *q;
    public:

    Queue(ll c){
        front = rear = 0;
        capacity = c;
        q = new ll[c];
    }

    ~Queue(){
        delete[] q;
    }

    void push(ll data){
        if(rear == capacity){
            cout << "Stack Overflow!\n";
        } else {
            q[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout << "Stack Underflow!\n";
        } else {
            for (int i = 0; i < rear - 1; i++) { 
                q[i] = q[i + 1]; 
            }
            rear--;
        }
    }

    ll peek(){
        if(front == rear){
            cout << "Stack is empty!\n";
            return 0;
        } else {
            return q[front];
        }
    }

    ll size(){
        return rear;
    }

    bool empty(){
        return front == rear;
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    Queue q(n);
    for(ll i = 0; i < n; i++){
        ll data;
        cin >> data;
        q.push(data);
    }

    cout << q.size() << "\n";

    while(!q.empty()){
        ll val = q.peek();
        cout << val << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
