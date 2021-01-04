#include<iostream>

using namespace std;
static const int N = 100;

int main(){
    int i,j,n,u,k,v;
    int G[N][N];
    cin >> n;
    for(i = 0; i < n; i++){
        G[i][i] = 0;
    }
    for(i = 0; i < n; i++){
        cin >> u >> k; // u=番号 k=つながってるノード数
        u--;
        for(j = 0; j < k; j++){
            cin >> v;
            v--;
            G[u][v] = 1;            
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
}