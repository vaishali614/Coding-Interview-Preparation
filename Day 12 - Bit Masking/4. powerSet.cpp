/** Power Set **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

vector<ll> helper(ll a[], ll n){
    vector<ll> v;
    ll i = 0;
    while(n > 0){
        if(n & 1) 
            v.pb(a[i]);
        i++;
        n = n >> 1;
    }
    return v;
}

vector<vector<ll>> powerSet(ll a[], ll n){
    vector<vector<ll>> ans;
    ll r = (1 << n) - 1;
    for(ll i = 0; i <= r; i++){
        vector<ll> v = helper(a, i);
        ans.pb(v);
    }
    return ans;
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

    vector<vector<ll>> subsets = powerSet(a, n);
    for(ll i = 0; i < subsets.size(); i++){
        for(ll j = 0; j < subsets[i].size(); j++){
            cout << subsets[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
