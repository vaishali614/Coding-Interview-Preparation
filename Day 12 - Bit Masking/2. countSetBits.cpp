/** Count total number of set bits **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll countSetBits(ll n){
    ll count = 0;
    while(n){
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = countSetBits(n);
    cout << ans << "\n";

    return 0;
}
