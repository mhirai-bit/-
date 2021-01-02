#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {int p, l, r;};

Node T[MAX];
int n, D[MAX];

void print(int u){ //0からn - 1の各idに対してprintを行う
    int i, c;
    cout << "node " << u << ": "; //nodeのid
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";

    //nodeのタイプの出力
    if(T[u].p == NIL) cout << "root, ";
    else if(T[u].l == NIL) cout << "leaf, "; //左に子がいなければleaf
    else cout << "internal node, ";

    cout << "[";
    for(i = 0, c = T[u].l; c != NIL; i++, c = T[c].r){
        if(i) cout << ", ";
        cout << c;
    } 
    cout << "]" << endl;
}


//再帰的に深さを求める
int rec(int u, int p){
    D[u] = p; //Dは最初の時点でカラ。uには0が最初に来る。
    if(T[u].r != NIL) rec(T[u].r, p); //右の兄弟にも同じ深さを設定 T[u].rは右兄弟のid。Dに対してidをindexにすると深さが得られる
    if(T[u].l != NIL) rec(T[u].l, p + 1); //最も左の子に自分の深さ+1を設定
}

int main() {
    int i, j, d, v, c, l, r;
    cin >> n;
    for(i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL; //全てのnodeを初期化
    
    for(i = 0; i < n; i++){
        cin >> v >> d; //v = id, d = 子の数(次数)
        for(j = 0; j < d; j++){ //次数の数だけforを回して子のidを取得
            cin >> c;
            if(j == 0) T[v].l = c; //j==0つまりrootなら左の子にcを設定
            else T[l].r = c; //rootじゃない場合は右の兄弟にcを設定
            l = c; //取得したidをlに設定
            T[c].p = v; //取得したnodeの親を設定
        }
    }
    for(i = 0; i < n; i++){
        if(T[i].p == NIL) r = i; //親がNIL、つまりrootの場合、rにそのidを代入
    }
    rec(r, 0); //rootのidをrとして関数をコール
    for(i = 0; i < n; i++) print(i); //プリント

    return 0;
}