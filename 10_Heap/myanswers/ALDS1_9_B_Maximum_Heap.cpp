#include<iostream>
using namespace std;
#define MAX 100000

int A[MAX], H;

void Maxheapify(int i){
    int right, left, largest;
    left = i * 2;
    right = i * 2 + 1;
    if(left <= H && A[i] < A[left]) largest = left;
    else largest = i;
    if(right < H && A[largest] < A[right]) largest = right;
    cout << "finish comparison\n";
    if(largest != i){
        swap(A[i], A[largest]);
        Maxheapify(largest);
    }
    cout << "finish swap\n";
}

int main(){
    int i;
    scanf("%d", &H);
    for(i = 1; i <= H; i++){
        cin >> A[i];
    }
    printf("read\n");
    for(i = H/2; i >= 1; i--){
        Maxheapify(i);
    }
    printf("sort\n");
    for(i = 1; i <= H; i++){
        cout << " " << A[i];
    }
    return 0;
}