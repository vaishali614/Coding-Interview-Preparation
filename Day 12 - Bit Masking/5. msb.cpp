/** Find MSB of a number in O(1) **/
/* 
 1) keep dividing n by 2 until it becomes 0 and count the number of steps
 2) use bitmasking
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll setBit(ll n){
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);

    n = n + 1;
    return (n >> 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = setBit(n);
    cout << ans << "\n";

    return 0;
}
