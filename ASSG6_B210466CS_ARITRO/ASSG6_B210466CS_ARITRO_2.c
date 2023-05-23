#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * next;
    int val;
};

struct LinkedList{
    struct node* top;
};

struct node* create_Node(int k){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->val=k;
    temp->next=NULL;
    return temp;
}

void Push(struct LinkedList *L, int k){
    struct node* temp=create_Node(k);
    temp->next=L->top;
    L->top=temp;
}


int Pop(struct LinkedList * L){
    if (L->top==NULL){
        return -1;
    }
    int temp=L->top->val;
    L->top=L->top->next;
    return temp;
}

void stack_empty(struct LinkedList * L){
    if( L->top==NULL) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int temp;
    char op='x';
    struct LinkedList* L=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    L->top=NULL;
    while(op!='t'){
        scanf("%c",&op);
        if (op=='i'){
            scanf("%d",&temp);
            Push(L,temp);

        }
        else if (op=='d'){
            scanf("%d",&temp);
            int temp1;
            while(temp--){
                temp1=Pop(L);
                if (temp1!=-1) printf("%d ", temp1);
                else printf("Empty ");
                }
            printf("\n");
        }
        else if (op=='e'){
            stack_empty(L);
        }
    }
}