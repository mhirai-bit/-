#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Node {
    int key;
    Node *prev, *next;
};

Node *nil;

Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void init() {
    nil = (Node*)malloc(sizeof(Node));
    nil->prev = nil;
    nil->next = nil;
}

void printList() {
    Node *cur = nil->next;
    bool first = 1;
    while(cur != nil){
        if (first == 1) {
            first = 0;
        }else{
            printf(" ");
        }
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *t){   
    t->next->prev = t->prev;
    t->prev->next = t->next;
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void insert(int key) {
    Node* x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->prev = nil;
    x->next = nil->next;
    nil->next = x;
    x->next->prev = x;
}

int main(){
    int n = 0, key;
    char command[20];
    scanf("%d", &n);
    init();
    for(int i = 0; i < n; i++){
        scanf("%s %d", command, &key);
            
        if(command[0] == 'i'){
            insert(key);
        }else if(command[0] == 'd'){
            if(command[6] == 'F'){deleteFirst();}
            else if(command[6] == 'L'){deleteLast();}
            else {deleteKey(key);}
        }
    }


    printList();
    return 0;
}