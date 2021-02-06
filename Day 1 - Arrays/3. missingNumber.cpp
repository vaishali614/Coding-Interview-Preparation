/** 3. Missing Number **/
/* 
 1) sort and compare with each index - T : O(nlogn) & S : O(1)
 2) use hashset to track occurrence of each element - T : O(n) & S : O(n) 
 3) (ans) bit manipulation - T : O(n) & S : O(1) => 
    ll ans = n;
    for(ll i = 0; i < n; i++){
        ans ^= (i ^ a[i]);
    }
 4) (ans) Gauss' Formula - T : O(n) & S : O(1)
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
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll ans = (n * (n + 1) / 2) - sum;   

    cout << ans << "\n";

    return 0;
}
