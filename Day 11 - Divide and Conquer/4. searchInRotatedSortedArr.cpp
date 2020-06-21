/** 4. Search an element in a rotated sorted array **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll search(ll a[], ll n, ll x) {
    if(n == 0) return -1;
    
    int s = 0, e = n - 1;
    while(s < e){
        int m = (s + e) / 2;
        if(a[m] > a[e]) s = m + 1;
        else e = m;
    }
    
    int start = s;
    s = 0;
    e = n - 1;
    
    if(x >= a[start] && x <= a[e]) s = start;
    else e = start;
    
    while(s <= e){
        int m = (s + e) / 2;
        if(a[m] == x) return m;
        else if(a[m] < x) s = m + 1;
        else e = m - 1;
    }
    return -1;
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
    
    ll x;
    cin >> x;

    ll ans = search(a, n, x);
    cout << ans << "\n";

    return 0;
}
