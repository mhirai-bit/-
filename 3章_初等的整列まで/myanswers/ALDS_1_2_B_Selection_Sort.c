#include<stdio.h>

int selectionSort(int A[], int N){
    int minj, t, sw = 0;
    for(int i = 0; i < N - 1; i++){
        minj = i;
        for(int j = i + 1; j < N; j++){
            if(A[j] < A[minj]) minj = j;
        }
        if(minj != i){
            t = A[i];
            A[i] = A[minj];
            A[minj] = t;
            sw++;
        }
    }
    return sw;
}

int main(){
    int A[100];
    int N;
    int sw = 0;

    scanf("%d", &N);
    for( int i = 0; i < N; i++) scanf("%d", &A[i]);
    sw = selectionSort(A, N);
    for( int i = 0; i < N; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", sw);
}