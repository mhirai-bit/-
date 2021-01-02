#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{int p,l,r;};
struct Node T[MAX];

void preOrder(int n){
    if(n == NIL) return;
    printf(" %d", n);
    preOrder(T[n].l);
    preOrder(T[n].r);
}

void inOrder(int n){
    if(n == NIL) return;
    inOrder(T[n].l);
    printf(" %d", n);
    inOrder(T[n].r);
}

void postOrder(int n){
    if(n == NIL) return;
    postOrder(T[n].l);
    postOrder(T[n].r);
    printf(" %d", n);
}

int main(){
    int i, n, v, l, r, root;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        T[i].p = T[i].r = T[i].l = NIL; //<=これがないと再帰処理が抜けずにプログラムが止まる
    }

    for(i = 0; i < n; i++){
        scanf("%d%d%d", &v,&l,&r);
        T[v].l = l;
        T[v].r = r;
        if(l != NIL) T[l].p = v;
        if(r != NIL) T[r].p = v;
    }

    for(i = 0; i < n; i++){
        if (T[i].p == NIL) root = i;
    }

    printf("Preorder\n");
    preOrder(root);
    printf("\n");
    printf("InOrder\n");
    inOrder(root);
    printf("\n");
    printf("PostOrder\n");
    postOrder(root);
    printf("\n");
    
    return 0;
}