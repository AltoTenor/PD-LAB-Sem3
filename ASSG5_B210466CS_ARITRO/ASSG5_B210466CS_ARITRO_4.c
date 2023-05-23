#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node * next;
    struct node * prev;
};

struct node* create_node(int k){
    struct node* new;
    new=malloc(sizeof(struct node));
    new->key=k;
    new->prev =NULL;
    new->next=NULL;
    return new;
}

struct node* list_search(struct node *head,int k){
    struct node *temp = head;
    
    while(temp != NULL) {
        if (temp->key==k) return temp;
        else temp = temp->next;
    }
    return NULL;
}

struct node* list_insert_front(struct node* head,int key){
    struct node * new_head=create_node(key);
    new_head->next=head;
    if (head!=NULL) head->prev=new_head;
    new_head->prev=NULL;
    return new_head;
}

struct node* list_insert_tail(struct node* head,int key){
    
    struct node *temp = head;
    struct node * new_tail=create_node(key);
    if (temp!=NULL){
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next=new_tail;
        new_tail->prev=temp;
        new_tail->next=NULL;
        return head;
    }
    else {
        return new_tail;
    }
}
void swap(struct node* head,int x,int y,int c){
    y=c+1-y;
    if (head==NULL || x>c || y<=0 ) printf("NULL");
    else{
        int tempc=0;
        struct node* temp=head;
        struct node* temp1;
        struct node* temp2;
        while(temp!=NULL){
            tempc++;
            if (tempc==x) temp1=temp;
            if (tempc==y) temp2=temp;
            temp=temp->next;
        } 
        // printf("C: %d D: %d %d",c,temp1->key,temp2->key);
        int tempo=temp1->key;
        temp1->key=temp2->key;
        temp2->key=tempo;
        temp=head;
        while(temp->next!=NULL){
            // printf("%d ",temp->key);
            temp=temp->next;
        } 
        while(temp!=NULL){
            printf("%d ",temp->key);
            temp=temp->prev;
        } 
    } 
    printf("\n");  
}


int main(){

    char op='x';
    int a,x,y;
    struct node* head;
    head=malloc(sizeof(struct node));
    head=NULL;
    int c=0;
    while(op!='e'){
        scanf("%c",&op);
        if (op=='f'){
            scanf(" %d",&a);
            head=list_insert_front(head,a);
            c++;
        }
        else if (op=='t'){   
            scanf(" %d",&a);
            head=list_insert_tail(head,a);
            c++;
        }
        else if (op=='p'){ 
            scanf(" %d",&x);
            scanf(" %d",&y);
            swap(head,x,y,c);
            }

    }
    return 0;
}

