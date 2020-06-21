/** 6. Median of an array **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

double findMedian(vector<ll> &A, vector<ll> &B) {
    int m = A.size(), n = B.size();
    
    if(m < n) 
        return findMedian(B, A);
    
    int start = 0, end = 2 * n;
    
    while(start <= end){
        int mid = start + (end - start) / 2;
        int mid1 = m + n - mid;
        
        double L1 = (mid1 == 0) ? INT_MIN : A[(mid1 - 1) / 2];	
        double L2 = (mid == 0) ? INT_MIN : B[(mid - 1) / 2];
        double R1 = (mid1 == m * 2) ? INT_MAX : A[(mid1) / 2];
        double R2 = (mid == n * 2) ? INT_MAX : B[(mid) / 2];
        
        if (L1 > R2) start = mid + 1;		
        else if (L2 > R1) end = mid - 1;	
        else return (max(L1,L2) + min(R1, R2)) / 2;	
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n1;
    cin >> n1;
    vector<ll> v1(n1);
    for(ll i = 0; i < n1; i++){
        cin >> v1[i];
    }

    ll n2;
    cin >> n2;
    vector<ll> v2(n2);
    for(ll i = 0; i < n2; i++){
        cin >> v2[i];
    }

    ll ans = findMedian(v1, v2);
    cout << ans << "\n";

    return 0;
}
