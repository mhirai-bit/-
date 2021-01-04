#include<iostream>

using namespace std;
#define SENTINEL 2000000000

int Left[50000/2 + 2];
int Right[50000/2 + 2];
int cnt = 0;



void merge(int A[], int n,int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++){
        Left[i] = A[left + i];
    }
    for(int i = 0; i < n2; i++){
        Right[i] = A[mid + i];
    }
    Left[n1] = Right[n2] = SENTINEL;
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(Left[i] <= Right[j]){
            A[k] = Left[i++];
        }else{
            A[k] = Right[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right){
    if(left + 1 < right) {
        int mid = (left + right)/2;
        mergeSort(A,n, left, mid);
        printf("left called\n");
        mergeSort(A,n, mid, right);
        printf("right called\n");
        merge(A, n,left, mid, right);
        printf("merge called\n");
    }
}

int main() {    
    int A[500000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){scanf("%d", &A[i]);}
    mergeSort(A,n, 0, n);

    for(int i = 0; i < n; i++){
        if(i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", cnt);    
}