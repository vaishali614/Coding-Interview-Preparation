/** Pascal's Triangle II - Return the nth row **/
/* T : O(n) & S : O(n) **/

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

    vector<int> v;
    long long int val = 1;
    for(int i = 1; i <= (n + 1); i++){
        v.push_back(val);
        val = val * (n + 1 - i) / i;
    }    
    
    for(ll i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
