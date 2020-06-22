/** Stack Implementation using Queue **/
/* T(push) : O(1) & T(pop) : O(n) - vice versa is also possible */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

class Stack{
    queue<int> q1, q2;
    int t;
    public:
    Stack(){
        t = -1;
    }

    void push(ll data){
        q1.emplace(data);
        t = data;
    }

    void pop(){
        while(q1.size() > 1){
            t = q1.front();
            q2.emplace(t);
            q1.pop();
        }
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    ll size(){
        return q1.size();
    }

    ll top(){
        return t;
    }

    bool empty(){
        return q1.empty() && q2.empty();
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
        ll val = s.top();
        cout << val << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
