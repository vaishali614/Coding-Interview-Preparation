/** 1. Duplicate in an array of n integers **/
/*
 1) if sorted, consecutive same element will be the answer - T : O(log n) & S : O(1)
 2) if not sorted, use double loop - T : O(n^2) & S : O(1)
 3) improve time, use freq array / set - T : O(n) & S : O(n)
 4) (ans) Floyd Cycle Detection - T : O(n) & S : O(1) 
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

    int slow = a[0];
    int fast = a[0];
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    
    slow = a[0];
    while(slow != fast){
        slow = a[slow];
        fast = a[fast];
    }

    cout << fast << "\n";

    return 0;
}
