#include<cstdio>
#define MAX 10000
#define NIL -1
using namespace std;

struct Node{int parent, left, right;};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int r, int u){
    if (r == NIL) return;
    D[r] = u;
    setDepth(T[r].left, u + 1);
    setDepth(T[r].right, u + 1);
}

int setHeight(int r){
    //if(r == NIL) return 0; // ←0を返してはダメ。これまでの加算がパーになる。
    int h1 = 0, h2 = 0;
    if(T[r].left != NIL)
        h1 = setHeight(T[r].left) + 1;
    if(T[r].right != NIL)
        h2 = setHeight(T[r].right) + 1;
    return H[r] = (h1 > h2 ? h1 : h2);
}

void print(int i){
    printf("node %d: parent = %d, ", i, T[i].parent);

    if(T[i].parent == NIL) printf("sibling = %d, ", NIL);
    else if(T[T[i].parent].left != NIL && T[T[i].parent].left != i) printf("sibling = %d, ", T[i].left);
    else if(T[T[i].parent].right != NIL && T[T[i].parent].right != i) printf("sibling = %d, ", T[i].right);
    //else printf("sibling = %d, ", NIL);
    int d = 0;
    if(T[i].left != NIL) d++;
    if(T[i].right != NIL) d++;
    printf("degree = %d, ", d);

    printf("depth = %d, height = %d, ",D[i], H[i]);
    
    if(T[i].parent == NIL) printf("root\n");
    else if(T[i].left != NIL || T[i].right != NIL) printf("internal node\n");
    else printf("leaf\n");
}

int main(){
    int n, v, l, r, root;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &v,&l,&r);
        T[v].left = l;
        T[v].right = r;
        if(l != NIL) T[l].parent = v;
        if(r != NIL) T[r].parent = v;
    }
    for(int i = 0; i < n; i++){
        if(T[i].parent == NIL) root = i;
    }
    
    setDepth(root, 0);
    setHeight(root);
    
    for(int i = 0; i < n; i++){
        print(i);
    }
    return 0;
}