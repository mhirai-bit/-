#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

#define MAX 100000

struct Node{
    Node* parent;
    Node* left;
    Node* right;
    int key;
};

Node *NIL, *root;

void insert(int k){

    Node *z = (Node*)malloc(sizeof(Node));
    z->key = k;
    z->parent = NIL;
    z->right = NIL;
    z->left = NIL;

    Node* x = root;
    Node* y = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z; //yはこの時点でNILの子を持つ親なのでその子として設定する
        }else{
            y->right = z;
        }
    }

}

void inOrder(Node* n){
    if (n == NIL) return;
    inOrder(n->left);
    cout << " " << n->key ;
    inOrder(n->right); 
}

void preOrder(Node* n){
    if(n == NIL) return;
    cout << " " << n->key;
    preOrder(n->left);
    preOrder(n->right);
}

int main(){
    int i,n,k;
    string com;
    scanf("%d", &n);
    for(i = 0; i < n;i++){
        cin >> com;
        if(com == "insert"){
            cin >> k;
            insert(k);
        }else if("print"){
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
    return 0;
}