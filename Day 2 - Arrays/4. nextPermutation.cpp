/** Next Permutation **/
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
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }

    int i;
    for(i = n - 1; i > 0; i--){
        if(v[i] > v[i - 1]){
            int t = 0;
            for(int j = i; j < n; j++){
                if(v[j] > v[i - 1]){
                    t = max(t, j);
                }
            }
            int x = v[i - 1];
            v[i - 1] = v[t];
            v[t] = x;
            break;
        }
    }
    
    reverse(v.begin() + i, v.begin() + n);

    for(ll i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    return 0;
}
