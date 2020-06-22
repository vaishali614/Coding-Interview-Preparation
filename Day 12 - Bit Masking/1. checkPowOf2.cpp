/** Check if a number is power of 2 **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll checkPowOf2(ll n){
    if(n & (n - 1))
        return false;
    else
        return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    bool flag = checkPowOf2(n);
    if(flag) cout << "Yes, its a power of 2!\n";
    else cout << "No, its not a power of 2!\n";

    return 0;
}
