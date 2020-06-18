/** 2. Sort an array of 0's 1’s 2’s without using extra space or sorting algo **/
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

    ll z = 0, t = n - 1, i = 0;
    while(i <= t){
        if(a[i] == 0){
            ll x = a[i];
            a[i++] = a[z];
            a[z++] = x;
        } else if(a[i] == 1){
            i++;
        } else {
            ll x = a[i];
            a[i] = a[t];
            a[t--] = x;
        }
    }

    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
