#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30);

int H, A[MAX+1];

void maxHeapify(int i){
    int left, right, largest;
    left = i * 2;
    right = i * 2 + 1;
    if(left <= H && A[left] > A[i]) largest = left;
    else largest = i;
    if(right <= H && A[right] > A[largest]) largest = right;

    if(i != largest){
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int extract(){
    int maxv;
    if(H < 1) return -INFTY;
    maxv = A[1];//取り除く対象である最大値を保持
    A[1] = A[H--];//最後尾を最初のアイテムにコピーし、H(サイズ)を1減らす
    maxHeapify(1);//整える
    return maxv;
}

void increaseKey(int i, int key){
    if(key < A[i]) return;
    A[i] = key;//最後尾に指定の値を代入
    while(i > 1 && A[i / 2] < A[i]){//親より大きければ親と交換
        swap(A[i], A[i/2]);
        i = i / 2;//入れ替えた親とその親の関係も確認するため、iを親のインデックスにして再ループ
    }
}

void insert(int key){
    H++;
    A[H] = -INFTY;//最後尾にものすごく小さい値を入れる
    increaseKey(H, key);
}

int main(){
    int key;
    char com[10];

    while(1){
        scanf("%s", com);
        if(com[0] == 'e' && com[1] == 'n') break;//end
        if(com[0] == 'i'){//insert
            scanf("%d", &key);
            insert(key);
        }else{//extract
            printf("%d\n", extract());
        }
    }
    return 0;
}