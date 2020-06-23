/** Nearest Smaller Element **/
/* T : O(n) & S : O(n) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

vector<ll> nearestSmaller(ll a[], ll n){
    vector<ll> v;
    stack<ll> s;
    for(ll i = 0; i < n; i++){
        while(!s.empty() && s.top() >= a[i])
            s.pop();

        if(s.empty())
            v.pb(-1);
        else
            v.pb(s.top());

        s.push(a[i]);
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

    vector<ll> v = nearestSmaller(a, n);
    for(auto e : v){
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
