/** Excel Column Sheet **/
/* T : O(n) && S : O(1) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    ll col = 0;
    for(ll i = 0; i < s.size(); i++){
        col = col * 26 + (s[i] - 'A' + 1);
    }

    cout << col << "\n";

    return 0;
}
