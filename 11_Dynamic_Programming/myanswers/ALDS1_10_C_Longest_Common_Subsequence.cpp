#include<iostream>
#include<string>
#include<algorithm>

#define MAX 100
using namespace std;


int lcs(string s1, string s2){
    int maxv = 0;
    s1 = ' ' + s1;//この処理を入れないと、最初の一文字が比較対象にならなくなってしまう。ex) s1=abcdef, s2=abcdefでmaxv=5
    s2 = ' ' + s2;//なぜなら、forループが1オリジンのため。1オリジンなのは、ループ処理の中にi - 1、j - 1が存在するため。
    int s1_size = s1.size();
    int s2_size = s2.size();
    int c[MAX][MAX];
    for(int i = 0; i < s1_size; i++) c[i][0] = 0;
    for(int i = 0; i < s2_size; i++) c[0][i] = 0;
    
    for(int i = 1; i < s1_size; i++){
        for(int j = 1; j < s2_size; j++){
            if(s1[i] == s2[j]) c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            maxv = max(c[i][j], maxv);
        }
    }
    return maxv;
}

int main(){
    int i,n;
    string s1, s2;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}