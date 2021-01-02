#include <iostream>
using namespace std;

int BubbleSort(int A[], int N){
    int sw = 0;
    bool flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        for(int j = N - 1; j > i ; j--){
            if(A[j-1] > A[j]){
                swap(A[j-1], A[j]);
                sw++;
                flag = 1;
            }
        }
    }
    // for(int i = 0; i < N; i++) {
    //     if(i != 0) cout << " ";
    //     cout << A[i];
    // }
    // cout << endl;
    return sw;
}

int main(){
    int N;
    int A[100];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    int sw = BubbleSort(A, N);
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}