/** Topological Sort **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

vector<ll> graph[100001];
bool visited[100001];
bool onstack[100001];
vector<int> toposort;

// Topological Sort - Detecting Cycles
bool dfs(ll node) {
    visited[node] = true;
    onstack[node] = true;
    
    for(auto child: graph[node]) {
        if(visited[child] && onstack[child]) {
            // There is a circle
            return true;
        } else if(!visited[child] && dfs(child)) {
            // There is a circle
            return true;
        }
    }
    onstack[node] = false;
    toposort.pb(node);
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        graph[a].pb(b);
    }

    bool flag = false;
    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            flag = flag || dfs(i);
            if(flag) break;
        }
    }

    if(!flag){
        reverse(toposort.begin(), toposort.end());
        for(auto e : toposort){
            cout << e << " ";
        }
        cout << "\n";
    } else {
        cout << "Cycle detected!\n";
    }

    return 0;
}
