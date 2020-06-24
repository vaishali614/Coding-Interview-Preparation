/** Bottom View of Binary Tree **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

map<ll, pair<ll, ll>> m;

class TreeNode{
    public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

void bottomView(TreeNode* root, ll height, ll hDist){
    if(root == NULL)
        return;

    if(m.find(hDist) == m.end()){
        m[hDist] = {root->data, height};
    } else {
        pair<ll, ll> p = m[hDist];
        if(height >= p.second){
            m[hDist] = {root->data, height};
        }
    }

    bottomView(root->left, height + 1, hDist - 1);
    bottomView(root->right, height + 1, hDist + 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    bottomView(root, 0, 0);

    for(auto val : m){
        pair<ll, ll> p = val.second;
        cout << p.first << " ";
    }
    cout << "\n";

    return 0;
}
