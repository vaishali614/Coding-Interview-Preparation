/** Pascal Triangle - Dynamic Programming **/
/* T : O(n^2) & S : O(n^2) */

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

    vector<vector<int>> v;
    
    if(n > 0){
        v.push_back({1});
        
        for(int i = 1; i < n; i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j = 1; j < v[i - 1].size(); j++){
                int a = v[i - 1][j - 1] + v[i - 1][j];
                v1.push_back(a);
            }
            v1.push_back(1);
            v.push_back(v1);
        }
    }
    
    for(ll i = 0; i < v.size(); i++){
        for(ll j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
