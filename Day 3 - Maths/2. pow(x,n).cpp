/** Pow(x, n) **/
/* T : O(log n) & S : O(1) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

double power(double x, ll n){
    if(n == 0) return 1;
    if(n == 1) return x;

    double p = power(x, abs(n / 2));
    p *= p;
    if(n & 1) p *= x;
    if(n < 0) return (1 / p);
    else return p;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    double x;
    ll n;
    cin >> x >> n;

    double p = power(x, n);
    cout << p << "\n";

    return 0;
}
