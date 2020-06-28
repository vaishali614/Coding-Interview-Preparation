/** Subsets of a string **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
 
void filterChars(string s, int n){
    int i = 0;
    while(n > 0){
        (n & 1) ? cout << s[i] : cout << "";
        i++;
        n = n >> 1;
    }
    cout << "\n";
}

void generateSubsets(string s){
    int n = s.size();
    int r = (1 << n) - 1;
    for(int i = 0; i <= r; i++){
        filterChars(s, i);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    generateSubsets(s);
    
    return 0;
}
