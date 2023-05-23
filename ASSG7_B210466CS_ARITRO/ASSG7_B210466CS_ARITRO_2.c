#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node * left;
    struct node * right;

};

struct Tree{
    struct node * root;
};

struct Stack{
    struct node ** arr;
    int top;
};

struct node* pop(struct Stack * S){
    struct node* temp=S->arr[S->top];
    S->top--;
    return temp;
}

void push(struct Stack * S,struct node * element){
    S->top++;
    S->arr[S->top]=element;
}

struct node * create_node(char dt){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=dt;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void construct(struct Tree * T,char exp[]){
    struct Stack* S=(struct Stack *)malloc(sizeof(struct Stack));
    S->arr=calloc(10000,sizeof(struct node));
    S->top=-1;

    for (int i=0;exp[i]!='\0';i++){
        struct node * temp=create_node(exp[i]);
        if (exp[i]>96 && exp[i]<123){
            push(S,temp);
        }
        else{
            struct node * right=pop(S);
            struct node * left=pop(S);
            temp->left=left;
            temp->right=right;
            T->root=temp;
            // printf("Root: %c\n Root Left:%c \n Root Right :%c \n",T->root->data,T->root->left->data,T->root->right->data);
            push(S,temp);
        }
    }
}

void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if (root!=NULL){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);   
    }
}

int main(){
    char op='x';
    struct Tree * T=malloc(sizeof(struct Tree));


    while (op!='t'){
        scanf("%c",&op);
        if (op=='e'){
            char exp[100];
            scanf("%s",exp);
            // printf("%s",exp);
            construct(T,exp);
        }
        else if (op=='i'){
            inorder(T->root);
            printf("\n");
        }
        else if (op=='p'){
            preorder(T->root);
            printf("\n");   
        }
        else if(op=='s'){
            postorder(T->root);
            printf("\n");
        }
    }
}