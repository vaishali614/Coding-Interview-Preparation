/** 7. h - index **/
/*
 1) if sorted, apply binary search - T : O(logn) & S : O(1)
    ll s = 0, e = n;
    while(s < e){
        ll m = s + (e - s) / 2;
        if(a[m] < (n - m)){
            s = m + 1;
        } else {
            e = m;
        }
    }
    ans = n - s;
 2) if not sorted - T : O(n) & S : O(1)
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> res(n + 1, 0);
    for(auto x : a){
        x >= n ? res[n]++ : res[x]++;
    }    

    ll ans;
    if(res[n] == n){ 
        ans = n;
        return 0;
    }
    for(ll i = n - 1; i >= 0; i--){
        res[i] += res[i + 1];
        if(res[i] >= i){
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
