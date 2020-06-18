/** 4. Merge two sorted arrays without using extra space **/
/*
 1) compare arr1 elements with min of arr2 and swap in case of arr1[i] > arr2[j] - T : O((m + n)logn) & S : O(1)
 2) start filling from m + n - 1 - T : O(m + n) & S : O(1)
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    ll a1[n];
    for(ll i = 0; i < (n - m); i++){
        cin >> a1[i];
    }
    ll a2[m];
    for(ll i = 0; i < m; i++){
        cin >> a2[i];
    }

    ll i = n - m - 1, j = m - 1;
    for(ll k = (n - 1); k >= 0; k--){
        if(j < 0)
            break;
        if(i >= 0 && a1[i] > a2[j])
            a1[k] = a1[i--];
        else
            a1[k] = a2[j--];
    }

    for(ll i = 0; i < n; i++){
        cout << a1[i] << " ";
    }

    return 0;
}
