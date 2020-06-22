/** Find unique element in an array which has all elements thrice except for one **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll singleNumber(ll a[], ll n) {
    ll ans = 0;
    ll arr[32];
    memset(arr, 0, sizeof(arr));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 32; j++){
            if(a[i] & (1 << j))
                arr[j]++;
        }
    }
    
    for(ll i = 0; i < 32; i++){
        arr[i] %= 3;
        if(arr[i]) 
            ans += (1 << i);
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
    
    ll ans = singleNumber(a, n);
    cout << ans << "\n";

    return 0;
}
