/** Stock Buy and Sell I **/
/* T : O(n) & S : O(1) */

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

    ll mx = 0, mn = INT_MAX;
    for(ll i = 0; i < n; i++){
        mn = min(mn, a[i]);
        mx = max(mx, (a[i] - mn));
    }

    cout << mx << "\n";
    
    return 0;
}
