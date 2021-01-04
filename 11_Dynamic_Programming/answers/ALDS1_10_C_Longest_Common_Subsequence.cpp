#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

static const int N = 1000;//int、longではここは1000じゃなく100にしたら動いた。cの宣言をdoubleにしたら1000でも動いた

int lcs(string X, string Y){
    //int c[N + 1][N + 1]; 教科書ではintで宣言していたが、doubleにしなければ関数lcs呼び出しと同時にプログラムが落ちた。
    //1000 * 1000でintの範囲である32,767を超えたため？
    double c[N + 1][N + 1];
    int m = X.size();
    int n = Y.size();
    //int maxl = 0;
    int maxl = 0;
    X = ' ' + X; // X[0]に空白を挿入
    Y = ' ' + Y; // Y[0]に空白を挿入
    for(int i = 0; i <= m; i++) c[i][0] = 0;
    for(int j = 1; j <= n; j++) c[0][j] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            
            if(X[i] == Y[j]) {
                //一致していたら両方落として、それより前のlcsに1を加算したものが答えとする
                c[i][j] = c[i - 1][j - 1] + 1;
            }else{
                //一致していなかったら片方を削るパターン同士で競わせる
                c[i][j] = max(c[i - 1][j], c[i][j - 1] );
            }
            maxl = max(maxl, c[i][j]);
        }
    }
    return maxl;
}

int main(){
    string s1, s2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;

        int a = 1;
        printf("");
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}