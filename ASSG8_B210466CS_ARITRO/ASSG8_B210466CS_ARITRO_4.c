#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
    int key;
    struct node * p;
    struct node * left;
    struct node * right;
};

struct tree{
    struct node * root;
};

struct node * create_node (int x){
    struct node * temp=malloc(sizeof(struct node));
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->p=NULL;
    return temp;
}

int lastind(char arr[]){
    int i=0;
    for (;arr[i]!='\0';i++);
    return i-2;
}

char * substring (char arr[],int i,int j){
    char* ans=malloc(10000*sizeof(char));
    int z=0;
    for (int k=i;k<=j;k++,z++){
        ans[z]=arr[k];
    }
    ans[z]='\0';
    return ans;
}

int stringtodec(char str[],int st,int end){
    char ans[100];
    int j=0;
    for (int i=st;i<=end;i++,j++){
        ans[j]=str[i];
    }
    ans[j]='\0';
    int x=atoi(ans);
    return x;
}


struct node * build_tree(char str[]){
    struct tree* T=malloc(sizeof(struct tree));
    T->root=NULL;
    int sz=lastind(str);
    struct node * temp;
    if (str[2]!=')'){
        int t,j=2;
        for (;str[j]!=' ';j++);
        t=stringtodec(str,2,j-1);
        temp=create_node(t);
    }
    else temp=NULL;     
    if (temp==NULL) return temp;
    else{
        int count=0,stk=0,firstopen;
        for (int i=3;i<=sz;i++){
            if (str[i]=='(' && stk==0){ 
                stk++;
                firstopen=i;
            }
            else if (str[i]=='(' && stk!=0){
                stk++;
            }
            else if(str[i]==')' && count==0){
                stk--;
                if (stk==0){
                    temp->left=build_tree(substring(str,firstopen,i));
                    count++;
                }
            }
            else if(str[i]==')' && count==1){
                stk--;
                if (stk==0){
                    temp->right=build_tree(substring(str,firstopen,i));
                    count++;
                }
            }            
            
        }
        return temp;
    } 
}

void postorder(struct node* root){
    if (root!=NULL){
        
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}

int main(){
    char str[10000];
    fgets(str,10000,stdin);
    struct tree* T=malloc(sizeof(struct tree));
    T->root=build_tree(str);
    postorder(T->root);
    // char st[]="-123";
    // int x=stringtodec(st,0,1);
    // printf("%d\n",x);

}
