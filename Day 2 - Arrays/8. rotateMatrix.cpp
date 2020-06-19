/** Rotate Matrix **/
/* T : O(n^2) & S : O(1) */

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
    ll a[n][n];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < i; j++){
            swap(a[i][j], a[j][i]);
        }
    }

    ll j = 0, k = n - 1;
    while(j < k){
        for(ll i = 0; i < n; i++){
            swap(a[i][j], a[i][k]);
        }
        j++;
        k--;
    }
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
