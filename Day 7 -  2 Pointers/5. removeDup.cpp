/** 5. Remove duplicates from sorted array **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll removeDup(ll a[], ll n) {
    if(n == 0) 
        return 0;
    
    int k = 0;
    for(int i = 1; i < n; i++){
        if(a[i] != a[k]){
            a[++k] = a[i];
        }
    }
    return k + 1;
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

    ll k = removeDup(a, n);
    for(ll i = 0; i < k; i++){
        cout << a[i] << " ";
    }

    return 0;
}
