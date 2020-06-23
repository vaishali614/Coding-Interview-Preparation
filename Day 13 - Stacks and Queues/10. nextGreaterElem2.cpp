/** Next Greater Element 2 **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

vector<ll> nextGreater(ll a[], ll n){
    vector<ll> v(n, -1);
    stack<ll> s;
    for(ll i = 0; i < 2 * n; i++){
        ll next = a[i % n];
        while(!s.empty() && a[s.top()] < next){
            v[s.top()] = next;
            s.pop();
        }
        if(i < n) s.push(i);
    }

    return v;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> v = nextGreater(a, n);
    for(auto e : v){
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
