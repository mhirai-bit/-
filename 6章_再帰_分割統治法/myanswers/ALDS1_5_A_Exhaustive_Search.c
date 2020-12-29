#include<iostream>
int n;

int A[20];
int solve(int i, int val){
    if (val == 0) return 1;
    if (i >= n) return 0;
    int res = solve(i + 1, val) || solve(i + 1, val - A[i]); //left means not addding i's item / right means adding i's item
    return res;
}


int main(){
    int q, val;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &val);
        if(solve(0, val)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}