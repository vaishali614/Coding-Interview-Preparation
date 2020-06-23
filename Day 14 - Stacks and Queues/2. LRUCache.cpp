/** LRU Cache **/
/* T : O(capacity) */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

class LRUCache {
    unordered_map<int, int> value, count;
    queue<int> accessed;
    int capacity;
    public:
    LRUCache(int c) {
        capacity = c;
    }
    
    int get(int key) {
        if(value.find(key) != value.end()){
            accessed.push(key);
            count[key]++;
            return value[key];
        }
        return -1;
    }
    
    void put(int key, int v) {
        if(((int) value.size() < capacity) || (value.find(key) != value.end())){
            value[key] = v;
            accessed.push(key);
            count[key]++;
            return;
        }
        
        while(true){
            int front = accessed.front();
            accessed.pop();
            if(--count[front] == 0){
                value.erase(front);
                break;
            }
        }
        value[key] = v;
        accessed.push(key);
        count[key]++;
    }
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    LRUCache lru(n);

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << " ";
    lru.put(3, 3);
    cout << lru.get(2) << " ";
    lru.put(4, 4);
    cout << lru.get(1) << " ";
    cout << lru.get(3) << " ";
    cout << lru.get(4) << " ";

    return 0;
}
