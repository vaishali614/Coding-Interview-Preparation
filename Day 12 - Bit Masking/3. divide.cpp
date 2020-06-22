/** Divide integers without using / operator **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll divide(ll a, ll b){
    ll sign = ((a < 0) ^ (b < 0) ? -1 : 1);
    a = abs(a);
    b = abs(b);

    ll q = 0, ans = 0;
    for(ll i = 31; i >= 0; i--){
        if(ans + (b << i) <= a){
            ans += (b << i);
            q |= 1LL << i;
        }
    }

    return sign * q;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b;
    cin >> a >> b;

    ll ans = divide(a, b);
    cout << ans << "\n";

    return 0;
}
