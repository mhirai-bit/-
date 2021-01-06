#include<iostream>
#include<queue>

using namespace std;
static const int N = 100;
static const int INFTY = (1 << 21);
int n, d[N], M[N][N];


void bfs(int start){
    int node;
    for(int i = 0; i < n; i++) d[i] = INFTY;

    queue<int> q;
    q.push(start);
    d[start] = 0;
    while(!q.empty()){
        node = q.front(); q.pop();
        for(int adj = 0; adj < n; adj++){
            if(M[node][adj] == 0) continue;//隣接ノードか?
            if(d[adj] != INFTY) continue;//未訪問か?
            q.push(adj);//条件を満たしていれば隣接ノードをqueueにpush
            d[adj] = d[node] + 1;//adjへの距離はnodeへの距離+1とする
        }
    }

    for(int i = 0; i < n; i++){
        cout << i + 1 << " " << ((d[i] == INFTY) ? -1 : d[i]) << endl;
    }
}

int main(){
    int i, j, id, deg, adj;
    cin >> n;
    for(i = 0; i < n; i++) M[i][i] = 0;

    for(i = 0; i < n; i++){
        cin >> id >> deg;
        id--;
        for(j = 0; j < deg; j++){
            cin >> adj;
            adj--;
            M[id][adj] = 1;
        }
    }

    bfs(0);
    return 0;
}