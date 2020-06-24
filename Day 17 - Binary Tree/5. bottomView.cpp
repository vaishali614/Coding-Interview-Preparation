/** Bottom View of Binary Tree **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

map<ll, vector<ll>> m;

class TreeNode{
    public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

void bottomView(TreeNode* root, ll hDist){
    if(root == NULL)
        return;

    m[hDist].pb(root->data);

    bottomView(root->left, hDist - 1);
    bottomView(root->right, hDist + 1);
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

    bottomView(root, 0);

    for(auto val : m){
        vector<ll> v = val.second;
        cout << v.back() << " ";
    }
    cout << "\n";

    return 0;
}
