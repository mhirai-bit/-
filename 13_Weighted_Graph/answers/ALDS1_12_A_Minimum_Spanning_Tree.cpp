#include<iostream>
using namespace std;
static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim(){
    int u, minv;
    //d[]->重みが最小の辺の重みを記録
    //p[]->頂点vの親を記録
    //color[]->訪問状態を記録
    int d[MAX], p[MAX], color[MAX];

    //それぞれ初期化
    for(int i = 0; i < n; i++){
        d[i] = INFTY;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(1){
        minv = INFTY;
        u = -1;
        //最小のものを選ぶ処理
        for(int i = 0; i < n; i++){
            if(minv > d[i] && color[i] != BLACK){//2回目の上段のforでd[]でINFTY以外が入っているのは2個目のforで発見された隣接ノードだけ
            //minv(最小の重み)よりもd[i]に記録してある重みが軽く、
            //かつそこが未訪問の場合
            //uにそのノードidを記録し、minvを上書きする
            //uはこの後始点として使用される
                u = i;
                minv = d[i];
            //forのi = 0のループでuとminvには0が入る
            //
            }
        }
        //u==-1ということはminvよりも小さい重みがないか、全て訪問済み
        if(u == -1) break;
        //uには最小の重み経路のつながるノードのidが入っているので
        //BLACKにして訪問済みとする
        color[u] = BLACK;
        //未訪問の隣接ノードとその重みを記録する処理
        for(int v = 0; v < n; v++){
            if(color[v] != BLACK && M[u][v] != INFTY){
            //ノードvに未訪問かつuからvへの経路が存在する場合(uには最小の重みで到達できるノードのidが入っている)
                if(d[v] > M[u][v]){
                //最初はd[v]にはINFTYが入っている(v=0の場合はcolor[u] == BLACKの代入でifに入れない)
                //つまり、このループでuと繋がりのあるvで未訪問かつ最小のものがd[v]に記録され、その親がp[v]に記録される
                //uからvへの重みが最小の重み未満の場合
                //d[v]をその重みで上書き
                //p[v]には親（出発元)であるuを入れる
                //vは訪問中ということでGRAYにする
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != -1) sum += M[i][p[i]];
    }
    return sum;
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int e; cin >> e;
            M[i][j] = (e == -1) ? INFTY : e;
        }
    }

    cout << prim() << endl;

    return 0;
}