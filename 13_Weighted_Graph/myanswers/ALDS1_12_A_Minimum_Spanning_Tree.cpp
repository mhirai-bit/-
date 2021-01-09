#include<iostream>
#include<vector>
using namespace std;
#define MAX 100
#define INFTY (1 << 21)
int visited[MAX];
int Graph[MAX][MAX];
int n; //number of nodes

int prim(){
    int sum = 0;
    vector<int> T;
    T.push_back(0);
    visited[0] = 1;
    int first = 1, min, min_node;
    //min = INFTY; //ここでINFTYにするとずっと同じノードがmin_nodeとなってしまう
    while(1){
        min = INFTY;//ここでINFTYにしないと、初回で最小の値がminに入った場合else ifを超えられずminがずっと上書きされないらしい
        for(int i = 0; i < T.size(); i++){//Tに入っている訪問済みノードの分だけforを回す
            for(int abj = 0; abj < n; abj++){//訪問済みノードに対して全ての隣接ノードを調べる
                if(visited[abj] == 0 && Graph[T[i]][abj] != INFTY){//隣接かつ未訪問の場合
                    if(min > Graph[T[i]][abj]){//最小の隣接のノードを調べる
                        min = Graph[T[i]][abj];
                        min_node = abj;
                    }
                }
            }
        }

        T.push_back(min_node);//最小の隣接ノードをTに追加
        visited[min_node] = 1;//そのノードは訪問済みとする
        // cout << "min = " << min << endl;
        // cout << "min_node = " << min_node << endl;
        sum += min;
        if(T.size() == n) break;//全ノード訪問が終わったらwhileを抜ける
    }

    //for(int i = 0; i < n; i++) cout <<  visited[i] << endl;
    return sum;
}

int main(){
    int i, j, a, b;
    cin >> n;
    for(i = 0; i < n; i++){
        visited[i] = 0;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> a;
            Graph[i][j] = (a == -1) ? INFTY : a;
        }
    }

    cout << prim() << endl;
    return 0;
}