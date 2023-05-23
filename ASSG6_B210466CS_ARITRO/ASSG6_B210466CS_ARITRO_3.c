#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int head;
    int tail;
    int* Arr;
    int size;
};

int queuefull(struct Queue * Q){
    if ((Q->tail+1)%Q->size==Q->head) return 1;
    else return 0;
}

int queueempty(struct Queue * Q){
    if (Q->tail==Q->head) return 1;
    else return 0;
}

void enqueue(struct Queue * Q, int k){
    if (queuefull(Q)){
        printf("Full\n");
        return;
    }
    Q->Arr[Q->tail]=k;
    Q->tail=(Q->tail+1)%(Q->size);
    
}

void dequeue(struct Queue * Q){
    if (queueempty(Q)){
        printf("Empty ");
        return;
    }
    printf("%d ",Q->Arr[Q->head]);
    Q->head=(Q->head+1)%Q->size;
}

int main(){
    int n,temp;
    char op='x';
    scanf("%d",&n);
    struct Queue *Q=(struct Queue *)malloc(sizeof(struct Queue));
    Q->Arr=calloc(n,sizeof(int));
    Q->head=0;
    Q->tail=0;
    Q->size=n;
    while(op!='t'){
        scanf("%c",&op);
        if (op=='i'){

            scanf("%d",&temp);
            enqueue(Q,temp);
        }
        else if (op=='d'){
            scanf("%d",&temp);
            int temp1;
            while(temp--){
                dequeue(Q);
                }
            printf("\n");
        }
        else if (op=='e'){
            if (queueempty(Q))printf("YES\n");
            else printf("NO\n");
        }
        else if (op=='f'){
            if (queuefull(Q))printf("YES\n");
            else printf("NO\n");
        }
        for (int i=0;i<4;i++)("Ok%d ",Q->Arr[i]);
    }
}