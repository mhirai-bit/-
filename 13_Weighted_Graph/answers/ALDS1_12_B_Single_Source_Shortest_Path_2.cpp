#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
static const int MAX = 10000;
static const int INFTY = (1 << 20);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int>> adj[MAX]; //重み付き有効グラフの隣接リスト表現

void dijkstra(){
    priority_queue<pair<int, int>> PQ;
    int color[MAX];
    int d[MAX];
    //初期化
    for(int i = 0; i < n; i++){
        d[i] = INFTY;//重み無限
        color[i] = WHITE;//未訪問
    }

    //出発点設定
    d[0] = 0;//出発点→出発点の重みはゼロ
    PQ.push(make_pair(0, 0));
    color[0] = GRAY;//訪問中

    while(!PQ.empty()){
        pair<int, int> f = PQ.top(); PQ.pop();//最大値が取れる
        int u = f.second;//重み
        color[u] = BLACK;//訪問済み

        //最小値を取り出し、それが最短でなければ無視
        if(d[u] < f.first * (-1)) continue;

        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].first;
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                //priority_queueはデフォルトで大きい値を優先するため-1を掛ける
                PQ.push(make_pair(d[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main(){
    int k, u, v, c;
    cin >> n;//ノード数の取得
    for(int i = 0; i < n; i++){
        cin >> u >> k;
        for(int j = 0; j < k; j++){
            cin >> v >> c;//ノードと重みの取得
            adj[u].push_back(make_pair(v, c));
        }
    }
    dijkstra();
    return 0;
}