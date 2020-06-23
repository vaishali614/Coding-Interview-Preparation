/** Sliding Window Maximum **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

vector<ll> maxSlidingWindow(vector<ll>& v, ll k) {
    ll n = v.size(), m = n - k + 1;
    if(n <= 1)
        return v;
    
    deque<ll> dq;
    vector<ll> ans;
    
    ll i = 0;
    for(; i < k; i++){
        while(!dq.empty() && v[dq.back()] < v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for(; i < n; i++){
        ans.push_back(v[dq.front()]);
        
        while(!dq.empty() && dq.front() <= (i - k)){
            dq.pop_front();
        }
        
        while(!dq.empty() && v[dq.back()] < v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    ans.push_back(v[dq.front()]);
    
    return ans;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }

    ll k;
    cin >> k;

    vector<ll> ans = maxSlidingWindow(v, k);
    for(ll e : ans){
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
