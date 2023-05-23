#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node * p;
    struct node * left;
    struct node * right;
};

struct BST{
    struct node* root;
};

struct node * create_node (int x){
    struct node * temp=malloc(sizeof(struct node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->p=NULL;
    return temp;
}


void insert(struct BST * B,int k){
    struct node * temp=create_node(k);
    struct node * y=NULL;
    struct node * x=B->root;
    while(x!=NULL){
        y=x;
        if (temp->key<x->key){
            x=x->left;
        }
        else x=x->right;
    }
    temp->p=y;
    if (y==NULL) B->root=temp;
    else if (temp->key<y->key) y->left=temp;
    else y->right=temp;

}

void preorder(struct node* root){
    if (root!=NULL){
        printf("( ");
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
        printf(") ");
    }
    else printf("( ) ");
}

int main(){
    struct BST * B=malloc(sizeof(struct BST));
    B->root=NULL;
    char op='x';
    int temp;
    while(op!='e'){
        scanf("%c",&op);
        if (op=='i'){
            scanf("%d",&temp);
            insert(B,temp);
        }
        else if (op=='p'){
            preorder(B->root);
            printf("\n");
        }
    }

}
