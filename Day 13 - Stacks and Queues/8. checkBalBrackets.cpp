/** Check Balanced Parentheses **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std;

bool isValid(string s) {
    stack<char> S;
    bool flag = true;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            S.push(s[i]);
        } else {
            if(s[i] == ')'){
                if(S.empty() || S.top() != '('){
                    flag = false;
                    break;
                } else {
                    S.pop();
                }
            } else if(s[i] == '}'){
                if(S.empty() || S.top() != '{'){
                    flag = false;
                    break;
                } else {
                    S.pop();
                }
            } else if(s[i] == ']'){
                if(S.empty() || S.top() != '['){
                    flag = false;
                    break;
                } else {
                    S.pop();
                }
            }
        }
    }
    if(S.empty())
        return flag;
    else
        return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    bool flag = isValid(s);
    if(flag) cout << "Brackets are balanced!\n";
    else cout << "Brackets aren't balanced!\n";

    return 0;
}
