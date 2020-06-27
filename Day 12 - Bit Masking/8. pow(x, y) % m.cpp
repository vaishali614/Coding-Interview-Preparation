/** Calculate pow(x, y) % m **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll power(ll x, ll y, ll m){
    ll ans = 1;
    
    x = x % m;
    if(x == 0) 
        return 0;
    
    while(y > 0){
        if(y & 1) 
            ans = (ans * x) % m;
      
        y = y >> 1;
        x = (x * x) % m;
    }
    
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x, y, m;
    cin >> x >> y >> m;

    ll ans = power(x, y, m);
    cout << ans << "\n";
    
    return 0;
}
