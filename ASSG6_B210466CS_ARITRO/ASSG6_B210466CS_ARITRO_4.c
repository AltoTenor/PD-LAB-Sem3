#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * next;
    int val;
};

struct LinkedList{
    struct node* head;
    struct node* tail;
};

struct node* create_Node(int k){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->val=k;
    temp->next=NULL;
    return temp;
}

void enqueue(struct LinkedList * L,int k){
    struct node * temp=create_Node(k);
    if (L->head==NULL && L->tail==NULL){
        L->head=temp;
        L->tail=temp;
    }
    else{
        L->tail->next=temp;
        L->tail=temp;
    }
}

void dequeue(struct LinkedList * L){
    if(L->head==NULL && L->tail==NULL){
        printf("Empty ");
        return;
    }
    else if (L->head==L->tail){
        printf("%d ",L->head->val);
        L->head=NULL;
        L->tail=NULL;
        return;
    }

    printf("%d ",L->head->val);
    L->head=L->head->next;
}

int queueempty(struct LinkedList * L){
    if(L->head==NULL && L->tail==NULL){
        printf("YES\n");
    }
    else printf("NO\n");
}

int main(){
    int temp;
    char op='x';
    struct LinkedList* L=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    L->head=NULL;
    L->tail=NULL;
    while(op!='t'){
        scanf("%c",&op);
        if (op=='i'){
            scanf("%d",&temp);
            enqueue(L,temp);
        }
        else if (op=='d'){
            scanf("%d",&temp);
            while(temp--){
                dequeue(L);
                }
            printf("\n");
        }
        else if (op=='e'){
            queueempty(L);
        }
    }
}