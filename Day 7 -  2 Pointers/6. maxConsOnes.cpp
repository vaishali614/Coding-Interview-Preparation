/** 6. Max consecutive ones **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int findMaxConsOnes(ll a[], ll n) {
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            sum++;
        } else {
            sum = 0;
        }
        ans = max(ans, sum);
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

    ll ans = findMaxConsOnes(a, n);
    cout << ans << "\n";

    return 0;
}
