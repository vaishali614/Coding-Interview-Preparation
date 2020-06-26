/* Number of islands */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

string grid[100001];

void dfs(string grid[], int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
        return;
    
    grid[i][j] = '2';
    
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i, j + 1, n, m);
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i, j - 1, n, m);
}

ll numIslands(string grid[], ll n) {
    if(n == 0) return 0;
    
    ll m = grid[0].size();
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                ans++;
                dfs(grid, i, j, n, m);
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

    for(ll i = 0; i < n; i++){
        cin >> grid[i];
    }

    ll ans = numIslands(grid, n);
    cout << ans << "\n";

    return 0;
}
