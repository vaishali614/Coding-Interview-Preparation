/** 2. Matrix Median **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll findMedian(vector<vector<ll> > &A) {
    ll mn = A[0][0], mx = A[0][0];
    ll n = A.size(), m = A[0].size();
    for(ll i = 0; i < n; ++i) {
        mn = min(mn, A[i][0]);
        mx = max(mx, A[i][m-1]);
    }

    ll elem = (n * m + 1) / 2;
    while (mn < mx) {
        ll mid = mn + (mx - mn) / 2;
        ll count = 0;
        for(ll i = 0; i < n; ++i)
            count += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0];
        if (count < elem)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v;
    for(ll i = 0; i < n; i++){
        vector<ll> v1(m);
        for(ll j = 0; j < m; j++){
            cin >> v1[j];
        }
        v.pb(v1);
    }

    ll ans = findMedian(v);
    cout << ans << "\n";

    return 0;
}
