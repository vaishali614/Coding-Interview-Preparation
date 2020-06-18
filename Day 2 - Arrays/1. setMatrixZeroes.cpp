/** 1. Set Matrix Zeros In-Place **/
/*
 1) use sets to store row num and column num and later fill all these rows and columns with 0 - T : O(n * m) & S : O(n + m)
 2) without using extra space, if we find a 0, we set all the rows and columns as INT_MIN and later mark all INT_MIN as 0 - T : O((n * m) * (n + m)) & S : O(1)
 3) just mark first row or col as 0 for the cell which is 0 - T : O(n * m) & S : O(1) 
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
    ll a[n][m];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    bool isCol = false;
    for(ll i = 0; i < n; i++){
        if(a[i][0] == 0)
            isCol = true;
        for(ll j = 1; j < m; j++){
            if(a[i][j] == 0){
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }
    
    for(ll i = 1; i < n; i++){
        for(ll j = 1; j < m; j++){
            if(a[i][0] == 0 || a[0][j] == 0){
                a[i][j] = 0;
            }
        }
    }
    
    if(a[0][0] == 0){
        for(ll i = 0; i < m; i++){
            a[0][i] = 0;
        }
    }
    
    if(isCol){
        for(ll i = 0; i < n; i++){
            a[i][0] = 0;
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
