/** 6. Max consecutive ones **/
/*
This problem won't be the actual problem asked in an interview, it'll be either a warm-up question or a follow-up question.
1. Simply iterate over the array and keep counting all 1's whenever you find one 1. Whenever you find a 0, update max and reset sum = 0. // T: O(N), S: O(1)
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int findMaxConsOnes(ll a[], ll n) {
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            sum++;
        } else {
            sum = 0;
        }
        ans = max(ans, sum);
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

    ll ans = findMaxConsOnes(a, n);
    cout << ans << "\n";

    return 0;
}
