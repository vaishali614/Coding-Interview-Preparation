/** 3. 3 sum **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

set<vector<ll>> findTriplets(ll a[], ll n){
    sort(a, a + n);
    set<vector<ll>> s;
    for(ll i = 0; i < n; i++){
        ll j = i + 1, k = n - 1;
        while(j < k){
            ll sum = a[i] + a[j] + a[k];
            if(sum == 0){
                s.insert({a[i], a[j], a[k]});
                j++;
                k--;
            } else if(sum < 0){
                j++;
            } else {
                k--;
            }
        }
    }
    return s;
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

    set<vector<ll>> s = findTriplets(a, n);
    for(auto e : s){
        for(ll j = 0; j < e.size(); j++){
            cout << e[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
