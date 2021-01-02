#include <stdio.h>

int pertition(int A[], int n){
    int i = 0, t;
    int x = A[n-1];
    for(int j = 1; j < n - 1; j++){
        if(A[j] <= x){
            t = A[j];
            A[j] = A[i];
            A[i] = t;
            i++; 
        }
    }
    t = A[i];
    A[i] = x;
    A[n-1] = t;
    return i;
}

int main(){
    int A[100000];
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &A[i]);

    int p = pertition(A, n);

    for(int i=0;i<n;i++){
        if(i) printf(" ");
        if(i == p) printf("[");
        printf("%d", A[i]);
        if(i == p) printf("]");
    }
}