/** Quick Sort **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void helper(ll a[], ll start, ll end){
    if(start >= end)
        return;
    ll pivot = end, sorted = start - 1;
    for(ll i = start; i < end; i++){
        if(a[i] <= a[pivot]){
            sorted++;
            swap(a[sorted], a[i]);
        }
    }
    swap(a[pivot], a[sorted + 1]);
    helper(a, start, sorted);
    helper(a, sorted + 2, end);
}

void quickSort(ll a[], ll n) {
    ll start = 0, end = n - 1;
    helper(a, start, end);
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
    
    quickSort(a, n);
    
    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
