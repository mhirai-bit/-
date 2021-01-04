#include<iostream>
using namespace std;

int main(){
    int F[50];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) F[i] = -1;
    F[0] = F[1] = 1;
    for(int i = 2; i < n; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
    for(int i = 0; i < n; i++) printf("%d\n", F[i]);
    return 0;
}