/** Queue Implementation using Stack **/
/* T(push, pop) : O(1) & T(peek) : O(n) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

class Queue{
    stack<int> s1, s2;
    int front;
    public:
    Queue(){
        front = -1;
    }

    void push(ll data){
        s1.push(data);
    }

    void pop(){
        s2.pop();
    }

    ll size(){
        return s1.size();
    }

    ll peek(){
        if(s2.empty()){
            while(!s1.empty()){
                front = s1.top();
                s2.push(front);
                s1.pop();
            }
        }
        int ans = s2.top();
        return ans;
    }

    bool empty(){
        return s1.empty() && s2.empty();
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

    cout << q.size() << "\n";

    while(!q.empty()){
        ll val = q.peek();
        cout << val << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}
