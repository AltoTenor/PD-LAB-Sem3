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


void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);   
    }
}

struct node * search(struct node * temp,int k){
    if (temp==NULL || temp->key==k) return temp;
    else if (k<temp->key) return search(temp->left,k);
    else return search (temp->right,k);
}

int max(struct node * temp){
    if (temp->right==NULL) return temp->key;
    else return max(temp->right);
} 

int min(struct node * temp){
    if (temp->left==NULL) return temp->key;
    else return min(temp->left);
} 



int main(){
    struct BST * B=malloc(sizeof(struct BST));
    B->root=NULL;
    char op='x';
    int temp;
    while(op!='e'){
        scanf("%c",&op);
        if (op=='a'){
            scanf("%d",&temp);
            insert(B,temp);
        }
        else if (op=='s'){
            scanf("%d",&temp);
            struct node * lost=search(B->root,temp);
            if (lost==NULL) printf("NotFound\n");
            else printf("Found\n");
        }
        else if(op=='x'){
            if (B->root==NULL) printf("NtIL");
            else printf("%d\n",max(B->root));
        }
        else if(op=='n'){
            if (B->root==NULL) printf("NIL");
            else printf("%d\n",min(B->root));
        }
        else if (op=='i'){
            if (B->root==NULL) printf("NIL");
            else inorder(B->root);
            printf("\n");
        }
        else if (op=='p'){
            if (B->root==NULL) printf("NIL");
            else preorder(B->root);
            printf("\n");
        }
        else if (op=='t'){
            if (B->root==NULL) printf("NIL");
            else postorder(B->root);
            printf("\n");
        }
    }

}