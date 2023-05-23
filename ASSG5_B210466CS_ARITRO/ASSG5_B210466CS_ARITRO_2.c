#include <stdio.h>
#include <stdlib.h>

struct node{
    char key;
    struct node* next;
};

struct node * create_node(char k){
    struct node *new;
    new=malloc(sizeof(struct node));
    new->key=k;
    new->next=NULL;
    return new;
}


struct node* list_insert_front(struct node* head,char key){
    struct node * new_head=create_node(key);
    new_head->next=head;
    return new_head;
}

struct node* list_insert_tail(struct node* head,char key){
    
    struct node *temp = head;
    struct node * new_tail=create_node(key);
    if (temp!=NULL){
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next=new_tail;
        return head;
    }
    else {
        return new_tail;
    }
}

struct node* delete_first(struct node* head){
    if (head==NULL){
        printf("NULL\n");
        return NULL;
        }
    else{
        printf("%c\n",head->key);
        head=head->next;
        return head;
    }
}

struct node* delete_last(struct node* head){
    struct node* temp=head;
    if (temp==NULL){
        printf("NULL\n");
        return NULL;
    }
    else if (temp->next!=NULL)
    {
        while(temp->next->next!=NULL){
            temp=temp->next;    
        }
        printf("%c\n",temp->next->key);
        temp->next=NULL;
        return head;
    }
    else{
        printf("%c\n",temp->key);
        return NULL;
    }
}

void printlist(struct node* head){
    struct node* temp=head;
    if (temp==NULL)printf("NULL");
    else{
        while(temp!=NULL){
            printf("%c ",temp->key);
            temp=temp->next;
        } 
    } 
    printf("\n");  
}



struct node* list_search(struct node *head,char k){
    struct node *temp = head;
    
    while(temp != NULL) {
        if (temp->key==k) return temp;
        else temp = temp->next;
    }
    return NULL;
}


void list_insert_after(struct node* head,char x,char y){
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
        return ins;
    }
    else{
        
        struct node *ins=create_node(temp->key);
        temp->key=x;
        ins->next=temp->next;
        temp->next=ins;
        return head;
    }
    
}

struct node* list_delete(struct node* head,char x){
    if (head==NULL){
        printf("NULL\n");
        return NULL;
    }


    struct node *temp=list_search(head,x);
    if (temp==NULL){
        printf("ABSENT\n");
        return head;
    }
    // struct node *temp1=list_search_before(head,x);
    else if (temp->next!=NULL){
        temp->key=temp->next->key;
        temp->next=temp->next->next;
        printf("%c\n",temp->key);
        return head;
    }
    else{
        printf("LAST\n");
        if(temp!=head){
            temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            return head;
        }
        else return NULL;
    }
}


int main(){

    char a,x,y,op='x';
    struct node* head;
    head=malloc(sizeof(struct node));
    head=NULL;
    while(op!='e'){
        scanf("%c",&op);
        if (op=='f'){
            scanf(" %c",&a);
            head=list_insert_front(head,a);
        }
        else if (op=='t'){   
            scanf(" %c",&a);
            head=list_insert_tail(head,a);
        }
        else if (op=='d'){   
            scanf(" %c",&a);
            head=list_delete(head,a);
        }
        else if (op=='a'){   
            scanf(" %c",&x);
            scanf(" %c",&y);
            list_insert_after(head,x,y);
        }
        else if (op=='b'){   
            scanf(" %c",&x);
            scanf(" %c",&y);
            head=list_insert_before (head,x,y);
        }
        else if (op=='i') head=delete_first(head);
        else if (op=='l') head=delete_last(head);
        else if (op=='p') printlist(head);
    }
    return 0;
}

