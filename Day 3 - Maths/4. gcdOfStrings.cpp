/** GCD of Two Strings **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    
    return gcd(b, (a % b));
}

string gcdOfStrings(string s1, string s2) {
    if(s1 + s2 != s2 + s1)
        return "";
    
    int g = gcd(s1.size(), s2.size());
    return s1.substr(0, g);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;

    string ans = gcdOfStrings(s1, s2);
    cout << ans << "\n";

    return 0;
}
