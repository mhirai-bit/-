#include <iostream>
using namespace std;
struct Node{
    int parent;
    int left_child;
    int right_sibling;
};
#define MAX 100000
#define NIL -1

Node N[MAX];
int Depth[MAX];


void rec(int u, int p){
    // Node node = N[id];
    // Depth[id] = 0;
    // while (node.parent != -1){ //rootかどうか確認
    //     Depth[id]++; //rootじゃないならidをインデックスにした深さを加算する
    //     node = N[node.parent]; //nodeの親を代入して親に対して次のループで同じことをする
    // }
    Depth[u] = p;
    if(N[u].right_sibling != NIL) rec(N[u].right_sibling, p);
    if(N[u].left_child != NIL) rec(N[u].left_child, p + 1);
}

void print(int id){
    int c;
    printf("node %d: parent = %d, depth = %d, ", id, N[id].parent, Depth[id]);
    if(N[id].parent == -1){
        printf("root, ");
    }else if(N[id].left_child != -1){
        printf("internal node, ");
    }else{
        printf("leaf, ");
    }
    printf("[");    
    for(int i = 0, c = N[id].left_child; c != NIL; i++, c = N[c].right_sibling){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main(){

    int i, j, n, child_sibling_id, node_id, num_of_kids, temp, r;
    cin >> n; //get the number of nodes
    for(i = 0; i < n; i++) N[i].parent = N[i].left_child = N[i].right_sibling = NIL; //全てのnodeを初期化
    for(i = 0; i < n; i++){
        //初期化
        // N[i].parent = - 1; //←すでに設定したものに上書きしてしまうからここでやってはだめだった。
        // N[i].left_child = -1;
        // N[i].right_sibling = -1;

        cin >> node_id >> num_of_kids;
        for(j = 0; j < num_of_kids; j++){
            cin >> child_sibling_id;
            if(j == 0){
                N[node_id].left_child = child_sibling_id;
            }else{
                N[temp].right_sibling = child_sibling_id;
            }
            // if (i == 0 && j == 0) N[node_id].parent = -1; //rootの場合 i = 0なら親だが、j=0でないと確実にnode_idがrootとは言えない。
            // else N[child_sibling_id].parent = i;//rootじゃない場合、親の設定
            temp = child_sibling_id;
            N[child_sibling_id].parent = node_id;
        }
    }
    for(i = 0; i < n; i++){
        if(N[i].parent == NIL) r = i;
    }
    rec(r, 0);
    for(i = 0; i < n; i++){
        print(i);
    }
    return 0;
}