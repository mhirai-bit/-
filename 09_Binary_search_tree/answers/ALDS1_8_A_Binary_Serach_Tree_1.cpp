#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL; //ともに0初期化

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node)); //新規追加のノード
    z->key = k; //キー設定
    z->left = NIL; //子供はNILで初期化
    z->right = NIL; //子供はNILで初期化

    while(x != NIL){ //nodeがNILでない場合に継続(rootとNILはグローバル宣言されているので初回は0初期化されている。なので初回はx(root) == NILとなる)
        y = x; //ひとつ前のnodeを保存
        if(z->key < x->key){
            x = x->left;//xには次のnodeが入る
        }else{
            x = x->right;//xには次のnodeが入る
        }
    }
    z->parent = y;
    if(y == NIL){//y = NILで初期化されているので、これはwhileに入らなかったことを意味する
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, i, x;
    string com;
    
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        cin >> com;
        if(com == "insert"){
            scanf("%d", &x);
            insert(x);
        }else if(com == "print"){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }

    return 0;
}