/** Stack Implementation using arrays **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

class Stack{
    ll top;

    public:
    ll a[MAX];

    Stack(){
        top = -1;
    }

    void push(ll data){
        if(top >= MAX - 1){
            cout << "Stack Overflow!\n";
        } else {
            top++;
            a[top] = data;
        }
    }

    void pop(){
        if(top < 0){
            cout << "Stack Underflow!\n";
        } else {
            top--;
        }
    }

    ll peek(){
        if(top < 0){
            cout << "Stack is empty!\n";
            return 0;
        } else {
            return a[top];
        }
    }

    ll size(){
        return top + 1;
    }

    bool empty(){
        return top < 0;
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

    cout << s.size() << "\n";

    while(!s.empty()){
        ll val = s.peek();
        cout << val << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
