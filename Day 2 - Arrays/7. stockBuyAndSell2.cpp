/** Stock Buy and Sell II **/
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

    int i, mx = 0, curr, next, buy = 0, sell = 0;
    bool isBuy = false;
    
    for(i = 0; i < (n - 1); i++){
        curr = a[i], next = a[i + 1];
        if(!isBuy && curr < next){
            buy = curr;
            mx -= buy;
            isBuy = true;
        } 
        if(isBuy && curr > next){
            sell = curr;
            mx += sell;
            isBuy = false;
        }
    }
    
    if(isBuy)
        mx += a[i];

    cout << mx << "\n";
    
    return 0;
}
