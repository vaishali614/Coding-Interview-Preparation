/** Next Greater Element **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

vector<pair<ll, ll>> nextGreater(ll a[], ll n){
    vector<pair<ll, ll>> v;
    if(n == 0)
        return v;
    stack<ll> s;
    s.push(a[0]);
    for(ll i = 1; i < n; i++){
        ll next = a[i];
        while(!s.empty() && s.top() < next){
            v.pb({s.top(), next});
            s.pop();
        }
        s.push(next);
    }

    while(!s.empty()){
        v.pb({s.top(), -1});
        s.pop();
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

    vector<pair<ll, ll>> v = nextGreater(a, n);
    for(auto e : v){
        cout << e.first << " - " << e.second << "\n";
    }

    return 0;
}
