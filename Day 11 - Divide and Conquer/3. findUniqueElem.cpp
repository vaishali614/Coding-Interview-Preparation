/** 3. Find Unique Element **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll findUnique(ll a[], ll n){
    int s = 0, e = n - 1;
    
    if(e == 0) return a[0];
    else if(a[s] != a[s + 1]) return a[s];
    else if(a[e] != a[e - 1]) return a[e];
    
    while(s <= e){
        int m = s + (e - s) / 2;
        if(a[m] != a[m - 1] && a[m] != a[m + 1]){
            return a[m];
        } else if((m % 2 && a[m] == a[m - 1]) || (!(m % 2) && a[m] == a[m + 1])){
            s = m + 1;
        } else {
            e = m - 1;
        }
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

    ll ans = findUnique(a, n);
    cout << ans << "\n";

    return 0;
}
