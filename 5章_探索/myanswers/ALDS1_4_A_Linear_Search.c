#include <stdio.h>

int S[1000];

int LinearSearch(int key, int n){
    S[n] = key;
    int i = 0;
    while(S[i] != key){i++;};
    return !(i == n);
}

int main(){
    int n = 0, m = 0, num = 0, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        S[i] = num;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &num);
        if(LinearSearch(num, n)){
            count++;
        }
    }   
    printf("%d\n", count);
}