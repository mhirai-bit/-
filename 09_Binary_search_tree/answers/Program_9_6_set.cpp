#include<iostream>
#include<set>
using namespace std;

void print(set<int> S){
    cout << S.size() << ":";
    for(set<int>::iterator it = S.begin(); it != S.end(); it++){
        cout << " " << (*it);
    }
    cout << endl;
}

int main() {
    set<int> S;

    S.insert(8);
    S.insert(1);
    S.insert(7);
    S.insert(4);
    S.insert(8);
    S.insert(4);

    print(S); // 4: 1 4 7 8
    S.erase(7);
    print(S); // 3: 1 4 8
    S.insert(2);
    print(S); // 4: 1 2 4 8

    if(S.find(10) == S.end()) cout << "not found." << endl;

    return 0; 
}

