#include<iostream>
#include<stack>
#include<vector>
using namespace std;

static const int MAX = 100;
static const int NIL = -1;
int n;//number of nodes
int color[MAX];
vector<int> Graph[MAX];

void dfs(int node_id, int color_id){
    int top_stack;
    int adj_id;
    stack<int> S;
    S.push(node_id);
    color[node_id] = color_id;
    
    while(!S.empty()){
        top_stack = S.top(); S.pop();
        for(int i = 0; i < Graph[top_stack].size(); i++){
            adj_id = Graph[top_stack][i];//fetching nodes pushed back to the Graph in main() one by one
            if(color[adj_id] == NIL){// if this node has never been visited
                color[adj_id] = color_id; // colorize it
                S.push(adj_id); // push it to the stack to check it's neighbor later
            }
        }
    }
}

void assigncolor(){
    int color_id = 1;
    for(int i = 0; i < n; i++) color[i] = NIL;
    for(int node_id = 0; node_id < n; node_id++){
        if(color[node_id] == NIL){
            dfs(node_id, color_id++);
        }
    }
}

int main(){
    int i, j;
    int rel;//number of relationships
    int a, b; //node a and b
    int q; //number of questions

    cin >> n >> rel;
    for(i = 0; i < rel; i++){
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    assigncolor();

    cin >> q;
    for(i = 0; i < q; i++){
        cin >> a >> b;
        if(color[a] == color[b]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}