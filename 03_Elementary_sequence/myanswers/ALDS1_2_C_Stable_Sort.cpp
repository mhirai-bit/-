#include<iostream>
using namespace std;

struct Card{char suit, value;};

void bubble(Card C[], int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = N - 1; j > i; j--){
            if(C[j].value < C[j - 1].value){
                swap(C[j], C[j - 1]);
            }
        }
    }
}

void select(Card C[], int N){
    int minj;
    for(int i = 0; i < N - 1; i++){
        minj = i;
        for(int j = i; j < N; j++){
            if(C[minj].value > C[j].value){
                minj = j;
            }
        }
        if(minj != i){
            // Card t = C[i];
            // C[i] = C[minj];
            // C[minj] = t;
            swap(C[i], C[minj]);
        }
    }
}

void print(Card C[], int N){
    for(int i = 0; i < N; i++){
        if(i != 0) cout << " ";
        cout << C[i].suit << C[i].value;
    }
    cout << endl;
}

bool isStable(Card C1[], Card C2[], int N){
    for(int i = 0; i < N; i++){
        if(C1[i].suit != C2[i].suit || C1[i].value != C2[i].value) {
            return false;
        }
    }
    return true;
}

int main(){
    Card C1[36], C2[36];
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> C1[i].suit >> C1[i].value;
    }
    for(int i = 0; i < N; i++){
        C2[i] = C1[i];
    }

    bubble(C1, N);
    select(C2, N);
    print(C1, N);
    cout << "Stable" << endl;
    print(C2, N);
    if(isStable(C1, C2, N)){
        cout << "Stable" << endl;
    }else
    {
        cout << "Not stable" << endl;
    }
    return 0;
}