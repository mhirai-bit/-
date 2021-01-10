#include<iostream>
#include<queue>
using namespace std;
#define MAX 100
#define INFTY (1 << 21)
int Weight[MAX];
int Graph[MAX][MAX];
int visited[MAX];
int n;//number of nodes



void dijkstra(){
    queue<int> Nodes;
    Nodes.push(0);
    visited[0] = 1;
    Weight[0] = 0;
    while(!Nodes.empty()){
        int node = Nodes.front();
        Nodes.pop();
        for(int adj = 0; adj < n; adj++){
            if(Graph[node][adj] != INFTY && visited[adj] == 0){
                Nodes.push(adj);
                visited[adj] = 1;
                if(Weight[adj] > Graph[node][adj] + Weight[node]){
                    Weight[adj] =  Graph[node][adj] + Weight[node];
                }
            }
        }       
    }
    for(int i = 0; i < n; i++){
        cout << i << " " << Weight[i] << endl;
    } 
}

int main(){
    int id, deg, adj, weight;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Graph[i][j] = INFTY;
        }      
        Weight[i] = INFTY;
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> id >> deg;
        for(int j = 0; j < deg; j++){
            cin >> adj >> weight;
            Graph[id][adj] = weight;
        }
    }
    dijkstra();
    return 0;
}