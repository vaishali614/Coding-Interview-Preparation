#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
 
vector<ll> edges[100001], result;
bool visited[100001];
ll inDeg[100001];
 
void initialise(ll n){
    memset(visited, false, sizeof(visited));
    for(ll i = 1; i <= n; i++) edges[i].clear(), inDeg[i] = 0;
}
 
void kahn(ll n){
    priority_queue<ll, vector<ll>, greater<ll> > q;
    for(ll i = 1; i <= n; i++){
        if(inDeg[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        ll front = q.top();
        result.pb(front);
        q.pop();
        for(auto child : edges[front]){
            inDeg[child]--;
            if(inDeg[child] == 0)
                q.push(child);
        }
    }
    
    if(result.size() != n) 
        cout << "Sandro fails.";
    else
        for(auto r : result){
            cout << r << " ";
        }
}
 
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        
        initialise(n);
        
        for(ll i = 0; i < m; i++){
            ll u, v;
            cin >> u >> v;
            edges[u].pb(v);
            inDeg[v]++;
        }
        
        kahn(n);
    }
    
    return 0;
} 
