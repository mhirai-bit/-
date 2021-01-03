#include<iostream>
#include<string>
using namespace std;
#define INFTY 1<<30;
#define MAX 1000000
int H;
int A[MAX];

void arrange(int i){
    int left, right, largest;
    left = i * 2;
    right = i * 2 + 1;
    if(left <= H && A[left] > A[i]) largest = left;
    else largest = i;
    if(right <= H && A[right] > A[largest]) largest = right;

    if(largest != i){
        swap(A[i], A[largest]);
        arrange(largest);
    }
}

void increaseKey(int i, int key){
    //if(key < A[i]) return ;
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        swap(A[i], A[i/2]);
        i = i / 2;
    }
}

void insert(int key){
    H++;
    //A[H] = -INFTY;
    increaseKey(H, key);
}

int extract(){
    int max;
    //if(H < 1) return -INFTY;
    max = A[1];
    A[1] = A[H--];
    arrange(1);
    return max;
}

int main(){
    int i, key, max;
    string com;

    while(1){
        cin >> com;
        if(com == "end") break;
        else if(com == "insert"){
            scanf("%d", &key);
            insert(key);
        }else if(com == "extract"){
            max = extract();
            cout << max << endl;
        }
    }
    return 0;
}