/** Left View of Binary Tree **/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
#define MAX 100000
using namespace std; 

class TreeNode{
    public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data){
        this->data = data;
        left = right = NULL;
    }
};

void leftView(TreeNode* root, ll level, ll* maxLevel){
    if(root == NULL)
        return;

    if(level > *maxLevel){
        cout << root->data << " ";
        *maxLevel = level;
    }

    leftView(root->left, level + 1, maxLevel);
    leftView(root->right, level + 1, maxLevel);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);

    ll maxLevel = 0;
    leftView(root, 1, &maxLevel);

    return 0;
}
