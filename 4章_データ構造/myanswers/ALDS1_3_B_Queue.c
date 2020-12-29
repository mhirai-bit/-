#include<stdio.h>
#include<string.h>
#define LEN 100005

typedef struct {
    char name[100];
    int time;
}P;

P Q[LEN];
int head = 1;
int tail;
void enqueue(P task){
    Q[tail] = task;
    tail = (tail + 1) % LEN;
}

P dequeue(){
    P val = Q[head];
    head = (head + 1) % LEN;
    return val;
}

int min(int a, int b) {return a < b ? a : b;}

int main(){

    int n, quontam, c, total = 0;
    scanf("%d %d", &n, &quontam);

    for(int i = 1; i <= n; i++){
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].time);
    }
    tail = n + 1;
    while(head != tail){
        P t = dequeue();
        c = min(quontam, t.time);
        t.time -= c;
        total += c;
        if( t.time > 0){
            enqueue(t);
        }else{
            printf("%s %d\n", t.name, total);
        }
    }
    return 0;
}


