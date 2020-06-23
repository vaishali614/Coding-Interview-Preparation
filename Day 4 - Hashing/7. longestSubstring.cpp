/** Longest substring wihtout repeating characters **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

ll longestSubstring(string s) {
    ll n = s.size(), i = 0, j = 0;
    set<char> st;
    ll ans = 0;
    while(i < n && j < n){
        if(st.find(s[j]) == st.end()){
            st.insert(s[j]);
            ans = max(ans, j - i + 1);
            j++;
        } else {
            st.erase(s[i]);
            i++;
        }
    }
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    ll ans = longestSubstring(s);
    cout << ans << "\n";

    return 0;
}
