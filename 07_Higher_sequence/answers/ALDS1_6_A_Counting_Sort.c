#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
    unsigned short *A, *B;

    int C[VMAX + 1];
    int n, i, j;
    scanf("%d", &n);
    
    A = malloc(sizeof(short) * n + 1);
    B = malloc(sizeof(short) * n + 1);

    for(i = 0; i <= VMAX; i++){
        C[i] = 0;
    }

    for(i = 0; i < n; i++){
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++; //値のインデックスの箇所を加算して発見回数をカウント
    }

    for(i = 1; i <= VMAX; i++){
        C[i] = C[i] + C[i - 1]; //累積加算していく
    }

    for(j = 1; j <= n; j++){
        B[C[A[j]]] = A[j]; //発見個数をインデックスにしてそこに対応する値A[j]を代入
        C[A[j]]--; //発見個数を代入したので1つ個数を減らす
    }

    for(i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    return 0;
    
}