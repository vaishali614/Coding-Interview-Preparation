/** 6. Merge overlapping subintervals **/
/*
 1) connected components - T : O(n^2) & S : O(n^2)
 2) sorting - O(nlogn) & S : O(1)
*/

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
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v.pb({a, b});
    }

    sort(v.begin(), v.end());

    vector<pair<ll, ll>> ans;
    for(auto e : v){
        ll m = ans.size();
        if(ans.empty() || ans[m - 1].second < e.first){
            ans.push_back(e);
        } else {
            ans[m - 1].second = max(ans[m - 1].second, e.second);
        }
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
