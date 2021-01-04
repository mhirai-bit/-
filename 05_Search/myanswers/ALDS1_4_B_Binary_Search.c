#include <stdio.h>

int A[1000];
int n = 0;

int binarySearch(int key){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(A[mid] == key) return 1;
        if(A[mid] > key){
            right = mid;
        }else if(A[mid] < key){
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    int i, q = 0, key, sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        if(binarySearch(key)) sum++;
    }

    printf("%d", sum);
    return 0;

}