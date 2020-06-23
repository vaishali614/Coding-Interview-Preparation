/** Largest Rectangle in Histogram **/
/* T : O(n) & S : O(n) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

int largestRectangleArea(ll h[], ll n){    
    if(n == 0) return 0;
    if(n == 1) return h[0];
    
    /*        _   _    
            _|_|_|_|_ 
          _| | | | | |_
        _|_|_|_|_|_|_|_|_
    */

    int ans = 0;
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; i++){
        int curr = h[i];
        if(curr >= h[s.top()]){
            s.push(i);
        } else {
            while(!s.empty() && curr < h[s.top()]){
                int temp = h[s.top()];
                s.pop();
                if(s.empty()){
                    ans = max(ans, temp * i);
                } else {
                    ans = max(ans, temp * (i - s.top() - 1));
                }
            }
            s.push(i);
        }
    }
  
    /* when we're at the minimum height among all
         _       _   
        | |_   _| |
        | | |_| | |                                          
       _|_|_|_|_|_|_
    */

    if(!s.empty()){
        int i = n;
        while(!s.empty()){
            int temp = h[s.top()];
            s.pop();
            if(s.empty()){
                ans = max(ans, temp * i);
            } else {
                ans = max(ans, temp * (i - s.top() - 1));
            }
        }   
    }
    
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = largestRectangleArea(a, n);
    cout << ans << "\n";

    return 0;
}
