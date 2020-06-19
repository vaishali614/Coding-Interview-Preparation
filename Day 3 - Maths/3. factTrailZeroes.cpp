/** Factorial Trailing Zeroes **/
/** T : O(log n) & S : O(1) */

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

    ll ans = 0, f = 5;
    while((n / f) != 0){
        ans += (n / f);
        f *= 5;
    }
    cout << ans << "\n";

    return 0;
}
