/** Find square of a number in O(log n) - without using *, /, pow() **/
/* 
 1) keep adding n, n number of times - T : O(n)
 2) use bitmasking
    if n is even, square(n) = 4 * square(n / 2)
    if n is odd, square(n) = 4 * square(n / 2) + 4 * (n / 2) + 1
    
    logic : (i) n = (2 * x) => n^2 = (2 * x)^2 = 4 * (x^2)
            (ii) n = (2 * x + 1) => n^2 = (2 * x + 1)^2 = 4 * (x^2) + 4 * x + 1
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

ll square(ll n){
    if(n == 0) 
        return 0;

    n = abs(n);

    ll f = (n >> 1);

    if(n & 1) 
        return ((square(f)) << 2) + (f << 2) + 1;
    else
        return (square(f) << 2);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    ll ans = square(n);
    cout << ans << "\n";

    return 0;
}
