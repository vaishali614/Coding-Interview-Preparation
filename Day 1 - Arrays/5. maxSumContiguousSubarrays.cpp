/** 5. Maximum sum contiguous subarray **/
/*
 1) prefix sum - T : O(n^2) & S : O(n)
 2) int sum = a[0], maxSum = a[0];
    for(int i = 1; i < a.size(); i++){
        int prevSum = sum + a[i];
        sum = max(prevSum, a[i]);
        maxSum = max(maxSum, sum);
    }
    T : O(n) & S : O(1);
 3) kadane's algorithm - T : O(n) & S : O(1) 
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll meh = 0, msf = INT_MIN;
    for(ll i = 0; i < n; i++){
        meh += a[i];
        if(meh < a[i]) 
            meh = a[i];
        if(meh > msf)
            msf = meh;
    }

    cout << msf << "\n";

    return 0;
}
