#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int tt = 0;     // time
int n;          //number of nodes
int G[N][N];    // graph
int f[N], l[N]; //first, last
int S[N];       //state


void dfs_visit(int i){
    S[i] = GRAY;//初回
    f[i] = ++tt;//時間記録
    for(int j = 0; j < n; j++){//iに対して隣接ノードをノード数nだけ探す
        if(G[i][j] == 1 && S[j] == WHITE){//最初はWHITEかどうかの確認が漏れていたが、それを入れなければWHITE以外にvisitしてしまう。
            dfs_visit(j);//隣接かつまだ訪ねていないノードであれば探索
        }
    }
    l[i] = ++tt;//dfs_visitから抜ける時に時間の記録とBLACKへの変更をする。
    S[i] = BLACK;//dfs_visitから抜ける=前回のノードに戻る事を意味するため。
}

void dfs(){
    for(int i = 0; i < n; i++){
        if(S[i] == WHITE){//StatusがWHITEなら探索
            dfs_visit(i);
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d %d %d\n", i, f[i-1], l[i-1]);
    }
}

int main(){
    int i,j,u,k,v;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        G[i][i] = 0;
        S[i] = WHITE;
    } 
    for(i = 0; i < n; i++){
        scanf("%d%d", &u,&k);
        u--;
        for(j = 0; j < k; j++){
            scanf("%d", &v);
            v--;
            G[u][v] = 1;
        }
    }

    dfs();
    return 0;
}
