#include<iostream>
#include<vector>
#include<stack>
using namespace std;
static const int MAX = 100000;
static const int NIL = -1;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c){
    stack<int> S;//stackの宣言はここ(dfs内)でいい。dfsが呼ばれるごとに新しいものを使用する
    S.push(r);//まずは現時点のノードであるrを隣接ノードを見つける基準としてstackにpushする
    color[r] = c;//idも、これからrに直接、間接的につながっている隣接ノードに振るidであるcをセットする
    while(!S.empty()){
        int u = S.top(); S.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];//G[u]にpush_backされたものが順番にiで選ばれる
            if(color[v] == NIL){//
            //選択された隣接ノードvの対応カラーとしてcを設定。あるノードに間接的にでも
            //つながっていれば、すべてにcが設定される
            //なぜなら、一回のdfs()のコールでwhile(!S.empty())は隣接ノードに隣接ノード存が在する限り
            //隣接ノードをstackにpushし続け、止まらないため
            //そしてプッシュされたノードの隣接ノードにカラーがついていなければ(color[v] == NIL)
            //同じカラー(c == id)が設定される。
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor(){
    int id = 1;
    for(int i = 0; i < n; i++) color[i] = NIL;//初期化
    for(int u = 0; u < n; u++) {//ノードの数だけ、0から見ていく
        //そのノード(u)の所属（color)がまだ決まっていない場合は、dfsを呼ぶ。決まっている場合は二度手間なので呼ぶ必要はない。
        if(color[u] == NIL) dfs(u, id++);//引数のidはcolorとしてセットされる値。dfs呼び出しにつき1つの値であればなんでもいい。
    }
}

int main(){
    int s, t, m, q;
    //ノード数と渡される関係数の読み込み
    cin >> n >> m;

    //関係の数だけ、相互にpush_backする
    for(int i = 0; i < m; i++){
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    assignColor();

    //質問の数を読み込み
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> s >> t;
        //同じcolorに属していれば、間接的にでもつながっていると見なせる
        if(color[s] == color[t]){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}