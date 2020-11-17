#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, pair<ll, ll>> mp;

class Tree {
    public:
    ll data;
    Tree* left;
    Tree* right;
    
    Tree(ll data){
        this->data = data;
    }
};

void leftView(Tree* root, ll level, ll *maxLevel){
    if(root == NULL)
        return;
        
    if(level > *maxLevel){
        cout << root->data << " ";
        *maxLevel = level;
    }
    
    leftView(root->left, level + 1, maxLevel);
    leftView(root->right, level + 1, maxLevel);
}

void rightView(Tree* root, ll level, ll *maxLevel){
    if(root == NULL)
        return;
        
    if(level > *maxLevel){
        cout << root->data << " ";
        *maxLevel = level;
    }
    
    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

void bottomView(Tree* root, ll height, ll hDist){
    if(root == NULL)
        return;
        
    if(mp.find(hDist) == mp.end())
        mp[hDist] = {root->data, height};
    else {
        pair<ll, ll> p = mp[hDist];
        if(p.second <= height){
            mp[hDist] = {root->data, height};
        }
    }
    
    bottomView(root->left, height + 1, hDist - 1);
    bottomView(root->right, height + 1, hDist + 1);
}

void topView(Tree* root, ll height, ll hDist){
    if(root == NULL)
        return;
        
    if(mp.find(hDist) == mp.end())
        mp[hDist] = {root->data, height};
    else {
        pair<ll, ll> p = mp[hDist];
        if(p.second > height){
            mp[hDist] = {root->data, height};
        }
    }
    
    topView(root->left, height + 1, hDist - 1);
    topView(root->right, height + 1, hDist + 1);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(3);
	root->left->left = new Tree(4);
	root->left->right = new Tree(5);
	
	ll maxLevel = 0;
	
	cout << "Left View : ";
	leftView(root, 1, &maxLevel);
	
	maxLevel = 0;
	cout << "\nRight View : ";
	rightView(root, 1, &maxLevel);
	
	cout << "\nBottom View : ";
	bottomView(root, 0, 0);
	
	for(auto e : mp){
	    pair<ll, ll> p = e.second;
	    cout << p.first << " ";
	}
	mp.clear();
	
	cout << "\nTop View : ";
	topView(root, 0, 0);
	
	for(auto e : mp){
	    pair<ll, ll> p = e.second;
	    cout << p.first << " ";
	}
	mp.clear();
	
	return 0;
}
