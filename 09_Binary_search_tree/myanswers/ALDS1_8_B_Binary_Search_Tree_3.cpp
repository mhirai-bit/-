#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

Node * FindMin(Node* x){
    while(x->left != NIL) x = x->left;
    return x;
}

Node* Delete(Node* root, int data){
    if(root == NIL) return root;
    else if(data < root->key) root->left = Delete(root->left, data);
    else if(data > root->key) root->right = Delete(root->right, data);
    else{//after found the node with the data
        if(root->left == NIL && root->right == NIL){// Case 1: No child
            free(root);
            root = NIL;
        }
        //Case 2: One child
        else if(root->left == NIL){
            Node *temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NIL){
            Node *temp = root;
            root = root->left;
            free(temp);
        }else{ // case 3: 2 children
            Node *temp = FindMin(root->right);//右側の最小値を持つnodeをtempに代入
            root->key = temp->key;//右側の最小値を削除対象のnodeの値に差し替え
            root->right = Delete(root->right, temp->key);//tempの移動元のnodeを削除
        }
    }
    return root;
}

Node* find(Node *u, int k){
    while(u != NIL && k != u->key){ //uが終点につくか、目的値を見つけるまでループ
        if(k < u->key){
            u = u->left;
        }else{
            u = u->right;
        }     
    }
    return u;
}

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

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
    int n,i,x;
    string com;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        cin >> com;
        if(com[0] == 'f'){
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NIL) printf("yes\n");
            else printf("no\n");
        }else if(com == "delete"){
            scanf("%d", &x);
            Delete(root, x);
        }else if(com == "insert"){
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