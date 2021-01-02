#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(){

    queue<pair<string, int>> Q;
    string name;
    int n = 0, q = 0, time = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> name >> time;
        Q.push(make_pair(name, time));
    }

    pair<string, int> u;
    int elaps = 0, c = 0;
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        c = min(u.second, q);
        u.second -= c;
        elaps += c;
        if(u.second > 0){
            Q.push(u);
        }else{
            cout << u.first << " " << elaps << endl;
        }
    }
    return 0;
}