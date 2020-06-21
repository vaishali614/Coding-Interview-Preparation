/** 4. Trapping Rain Water **/
/*
 1) Brute Force : ans += min(lmax, rmax) - a[i] - T : O(n^2) & S : O(1)
 2) DP : store leftmax, rightmax for each index i then use above formula - T : O(n) & S : O(n)
 3) 2 Pointer : T : O(n) & S : O(1)
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll trap(ll a[], ll n){        
    ll ans = 0, lmax = 0, rmax = 0;
    ll i = 0, j = n - 1;
    while(i <= j){
        lmax = max(lmax, a[i]);
        rmax = max(rmax, a[j]);
        if(lmax <= rmax){
            ans += lmax - a[i];
            i++;
        } else {
            ans += rmax - a[j];
            j--;
        }
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

    ll ans = trap(a, n);
    cout << ans << "\n";

    return 0;
}
