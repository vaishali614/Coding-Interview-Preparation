/** 2 Sum **/
/* T : O(n) & S : O(n) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

vector<ll> twoSum(ll a[], ll n, ll x) {
    vector<ll> ans;
    unordered_map<ll, ll> map;
    for(ll i = 0; i < n; i++){
        ll complement = x - a[i];
        if(map.count(complement)){ 
            ans.push_back(i);
            ans.push_back(map[complement]);
            break;
        }  
        map[a[i]] = i;
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

    ll x;
    cin >> x;

    vector<ll> v = twoSum(a, n, x);
    for(auto e : v){
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
