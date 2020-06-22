/** Breadth First Traversal **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

vector<ll> graph[100001];
bool visited[100001];

void bfs(ll node){
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        ll front = q.front();
        cout << front << " ";
        q.pop();
        for(auto child : graph[front]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
            }
        }
    }
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
        graph[b].pb(a);
    }

    bfs(1);

    return 0;
}
