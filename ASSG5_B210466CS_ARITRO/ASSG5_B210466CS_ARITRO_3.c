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

void list_insert_after(struct node* head,int x,int y){
    if (head==NULL){
        printf("NULL\n");
        return;
    }
    struct node *temp = list_search(head,y);
    if (temp==NULL){
        printf("ABSENT\n");
    }
    else{
        struct node *ins=create_node(x);
        ins->next=temp->next;
        ins->prev=temp;
        if (temp->next!=NULL ) temp->next->prev=ins;
        temp->next=ins;
    }
}

struct node* list_insert_before(struct node* head,int x,int y){ 
    
    struct node *temp = list_search(head,y);
    if (head==NULL){
        printf("NULL\n");
        return NULL;
    }
    else if (temp==NULL){
        printf("ABSENT\n");
        return head;
    }
    else if (y==head->key){
        struct node* ins=create_node(x);
        ins->next=head;
        head->prev=ins;
        return ins;
    }
    else{
        struct node *ins=create_node(temp->key);
        temp->key=x;
        temp->next->prev=ins;
        ins->next=temp->next;
        ins->prev=temp;
        temp->next=ins;
        return head;
    }
    
}

struct node* delete_first(struct node* head){
    if (head==NULL){
        printf("NULL\n");
        return NULL;
        }
    else{
        printf("%d\n",head->key);
        head=head->next;
        if (head!=NULL)head->prev=NULL;
        return head;
    }
}

struct node* delete_last(struct node* head){
    struct node* temp=head;
    if (head==NULL){
        printf("NULL\n");
        return NULL;
    }
    else if (head->next!=NULL)
    {
        while(temp->next->next!=NULL){
            temp=temp->next;    
        }
        printf("%d\n",temp->next->key);
        temp->next=NULL;
        return head;
    }
    else{
        printf("%d\n",temp->key);
        return NULL;
    }
}

void printlist(struct node* head){
    struct node* temp=head;
    if (temp==NULL)printf("NULL");
    else{
        while(temp!=NULL){
            printf("%d ",temp->key);
            temp=temp->next;
        } 
    } 
    printf("\n");  
}

void printrev(struct node* head,int x){
    struct node* temp=list_search(head,x);
    
    if (head==NULL)printf("NULL");
    else if (temp==NULL)printf("ABSENT");
    else{
        while(temp!=NULL){
            printf("%d ",temp->key);
            temp=temp->prev;
        } 
    } 
    printf("\n");
}

struct node* list_delete(struct node* head,int x){ 
    if (head==NULL){
        printf("NULL\n");
    }
    struct node *temp=list_search(head,x);
    if (temp==NULL){
        printf("ABSENT\n");
        
    }
    
    else if (temp->prev!=NULL){
        temp->key=temp->prev->key;
        temp->prev=temp->prev->prev;
        if(temp->prev!=NULL) temp->prev->next=temp;
        else if (temp->prev==NULL){
            printf("%d\n",temp->key);
            return temp;
        }
        printf("%d\n",temp->key);

    }
    else{
        printf("FIRST\n");
        temp=head->next;
        if (temp!=NULL) temp->prev=NULL;
        return temp;
    }
    return head;
}


int main(){

    char op='x';
    int a,x,y;
    struct node* head;
    head=malloc(sizeof(struct node));
    head=NULL;
    while(op!='e'){
        scanf("%c",&op);
        if (op=='f'){
            scanf(" %d",&a);
            head=list_insert_front(head,a);
        }
        else if (op=='t'){   
            scanf(" %d",&a);
            head=list_insert_tail(head,a);
        }
        else if (op=='d'){   
            scanf(" %d",&a);
            head=list_delete(head,a);
        }
        else if (op=='a'){   
            scanf(" %d",&x);
            scanf(" %d",&y);
            list_insert_after(head,x,y);
        }
        else if (op=='b'){   
            scanf(" %d",&x);
            scanf(" %d",&y);
            head=list_insert_before (head,x,y);
        }
        else if (op=='i') head=delete_first(head);
        else if (op=='l') head=delete_last(head);
        else if (op=='p') printlist(head);
        else if (op=='r'){   
            scanf(" %d",&a);
            printrev(head,a);
        }
    }
    return 0;
}

