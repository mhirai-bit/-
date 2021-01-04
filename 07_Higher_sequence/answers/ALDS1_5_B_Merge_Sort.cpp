#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2 + 2], R[MAX/ 2 + 2];
int cnt;

void merge(int A[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) L[i] = A[left + i]; //move left to the new array
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];  //move right to the new array
    L[n1] = R[n2] = SENTINEL; //番兵セット
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i++]; //小さいほうを大元の配列に入れていく
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right){
    if(left + 1 < right){
        int mid = (left + right)/2;
        mergeSort(A, n, left, mid); //left
        mergeSort(A, n, mid, right); //right
        merge(A, n, left, mid, right);
    }
}

int main(){
    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];

    mergeSort(A, n, 0, n);

    for(i = 0; i < n; i++){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}