#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Tree {
    public:
    ll data;
    Tree* left;
    Tree* right;
    
    Tree(ll data){
        this->data = data;
    }
};

void inorder(Tree* root){
    stack<Tree*> s;
    Tree* current = root;
    
    while(current != NULL || !s.empty()){
        while(current != NULL){
            s.push(current);
            current = current->left;
        }
        
        current = s.top();
        s.pop();
        
        cout << current->data << " ";
        
        current = current->right;
    }
}

void preorder(Tree* root){
    stack<Tree*> s;
    s.push(root);
    
    while(!s.empty()){
        Tree* current = s.top();
        s.pop();
        
        cout << current->data << " ";
        
        if(current->right)
            s.push(current->right);
        if(current->left)
            s.push(current->left);
    }
}

void postorder(Tree* root){
    stack<Tree*> s1, s2;
    s1.push(root);
    
    while(!s1.empty()){
        Tree* current = s1.top();
        s1.pop();
        
        s2.push(current);
        if(current->left)
            s1.push(current->left);
        if(current->right)
            s1.push(current->right);
    }
    
    while(!s2.empty()){
        Tree* current = s2.top();
        s2.pop();
        
        cout << current->data << " ";
    }
}

void inorderRec(Tree* root){
    if(root == NULL)
        return;
        
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}

void preorderRec(Tree* root){
    if(root == NULL)
        return;
        
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorderRec(Tree* root){
    if(root == NULL)
        return;
        
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(3);
	root->left->left = new Tree(4);
	root->left->right = new Tree(5);
	
	cout << "Inorder : ";
	inorder(root);
	cout << "\nPreorder : ";
	preorder(root);
	cout << "\nPostorder : ";
	postorder(root);
	
	cout << "\nInorder Recursive : ";
	inorderRec(root);
	cout << "\nPreorder Recursive : ";
	preorderRec(root);
	cout << "\nPostorder Recursive : ";
	postorderRec(root);
	
	return 0;
}
