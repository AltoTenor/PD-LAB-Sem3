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

struct node* minode(struct node * temp){
    if (temp->left==NULL) return temp;
    else return minode(temp->left);
} 

void successor(struct BST * B,int key){
    struct node* x=search(B->root,key);
    if (x->right!=NULL){
        printf("%d\n",min(x->right));
        return;
    }
    struct node * y=x->p;
    while(y!=NULL &&  x==y->right){
        x=y;
        y=y->p;
    }
    if (y==NULL) printf("NotFound\n");
    else printf("%d\n",y->key);
}


void predecessor(struct BST * B,int key){
    struct node* x=search(B->root,key);
    if (x->left!=NULL){
        printf("%d\n",max(x->left));
        return;
    }
    struct node * y=x->p;
    while(y!=NULL &&  x==y->left){
        x=y;
        y=y->p;
    }
    if (y==NULL) printf("NotFound\n");
    else printf("%d\n",y->key);
}


void transplant(struct BST * B,struct node* u,struct node * v){
    if(u->p==NULL) B->root=v;
    else if (u==u->p->left){
        u->p->left=v;
    }
    else u->p->right=v;
    if (v!=NULL) v->p=u->p;
}

void delete(struct BST * B,struct node * z){
    printf("%d\n",z->key);
    if (z->left==NULL){
        transplant(B,z,z->right);
    }
    else if (z->right==NULL){
        transplant(B,z,z->left);
    }
    else{
        struct node * y=minode(z->right);
        if (y->p!=z){
            transplant(B,y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        transplant(B,z,y);
        y->left=z->left;
        y->left->p=y;

    }
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
        else if (op=='d'){
            scanf("%d",&temp);
            struct node * z=search(B->root,temp);
            if (z==NULL) printf("NotFound\n");
            else delete(B,z);
        }
        else if(op=='c'){
            scanf("%d",&temp);
            successor(B,temp);
        }
        else if(op=='r'){
            scanf("%d",&temp);
            predecessor(B,temp);
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
    }

}