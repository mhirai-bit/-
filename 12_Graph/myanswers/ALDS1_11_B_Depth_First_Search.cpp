#include<iostream>
#include<stack>
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define N 100

using namespace std;

int n; //number of nodes
int G[N][N]; // Graph
int Color[N];
int f[N], l[N]; // first, last
int nt[N];
int id, deg, adj;
int tt = 0; //time;


int next(int p){
    for(int i = nt[p]; i < n; i++){
        //nが5だとすれば最後まで回して隣接ノードが見つかった場合nt[p]には5が入る
        //つまり二回目のnext()では-1をリターンする
        //１回目のnext()でWHITEでない隣接ノードを返しても、次はnext()が-1を返すので無限ループには入らない
        nt[p] = i + 1;
        if(G[p][i]) return i;
    }
    return -1;
}

void dfs_visit(int i){
    stack<int> S;
    int n, v; //node, visit
    for(int j = 0; j < n; j++) nt[j] = 0;
    S.push(i);
    f[i] = ++tt;
    Color[i] = GRAY;
    while(!S.empty()){
        n = S.top();
        v = next(n);
        if(v != -1){
            //隣接ノードがあった場合はpopを行わずスタックに隣接ノードを積んで次のイテレーションへ
            if(Color[v] == WHITE){
                S.push(v);
                f[v] = ++tt;
                Color[v] = GRAY;
            }
        }else{//隣接ノードがなかった場合
            S.pop();
            //38行目のコメントにあるように、参照されているスタックのトップ(n)に隣接ノードがない場合
            //その時スタックの一番上にあるnをpopする必要がある。修正前はiを使っていたのでうまく動かなかった。
            //iを使うと、whileから抜けるまで同じところのl[]を加算し続けてしまう。
            l[n] = ++tt;
            Color[n] = BLACK;
        }
    }
}

void dfs(){
    for(int i = 0; i < n; i++){
        Color[i] = WHITE;
    }
    for(int i = 0; i < n; i++){
        if(Color[i] == WHITE){
            dfs_visit(i);
        }
    }

    //プリント処理
    for(int i = 0; i < n; i++){
        cout << i+1 << " " << f[i] << " " << l[i] << endl;
    }
}

int main(){
    int i,j; // iteration
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> id >> deg;
        id--;
        for(j = 0; j < deg; j++){
            cin >> adj;
            adj--;
            G[id][adj] = 1;
        }
    }

    dfs();
    return 0;
}