#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int size;
    int* Arr;
};

void stack_empty(struct Stack* S){
    if (S->top==-1) printf("YES\n");
    else printf("NO\n");
}

void stack_full(struct Stack* S){
    if (S->top==S->size-1) printf("YES\n");
    else printf("NO\n");
}

void Push(struct Stack* S, int k){
    S->top++;
    S->Arr[S->top]=k;
}

void Pop(struct Stack* S){
    if (S->top==-1){
        printf("Empty ");
        return;
    }
    printf("%d ",S->Arr[S->top]);
    S->top--;
}

int main(){
    int temp,size;
    char op='x';

    scanf("%d",&size);

    struct Stack * S=(struct Stack *)malloc(sizeof(struct Stack));
    S->Arr=calloc(size,sizeof(int));
    S->size=size;
    S->top=-1;

    while(op!='t'){
        scanf("%c",&op);
        if (op=='i'){
            scanf("%d",&temp);
            if (S->top==S->size-1){ 
                printf("FULL\n");
                continue;
                }
            Push(S,temp);
            // for (int i=0;i<5;i++) printf("%d ", S->Arr[i]);
            // printf("Ignore\n");

        }
        else if (op=='d'){
            scanf("%d",&temp);
            while(temp--) Pop(S);
            printf("\n");
        }
        else if (op=='f'){
            stack_full(S);
        }
        else if (op=='e'){
            stack_empty(S);
        }

        
    }
}