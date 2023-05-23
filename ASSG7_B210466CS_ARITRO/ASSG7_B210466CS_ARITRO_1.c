#include <stdio.h>
#include <stdlib.h>


struct Stack{
    char *arr;
    int top;
};

char pop(struct Stack * S){
    char temp=S->arr[S->top];
    S->top--;
    return temp;
}

void push(struct Stack * S,char x){
    S->top++;
    S->arr[S->top]=x;
}

int sizestr(char str[]){
    int c=0;
    for (int i=0;str[i]!='\0';i++)c++;
    return c;
}
 
int precedence(char x){
    if (x=='+') return 0;
    else if (x=='-') return 0;
    else if (x=='*') return 1;
    else if (x=='/') return 1;
    else if (x=='(') return -1;
    else if (x==')') return -1;
}

int stackempty(struct Stack * S){
    if (S->top==-1) return 1;
    else return 0;
}

void infixtopostfix(char str[],struct Stack * S){
    int sz=sizestr(str);
    char ans[100000];
    int j=0;
    for (int i=0;i<sz;i++){
        
        if (str[i]>=90 && str[i]<=122) {
            ans[j]=str[i];
            j++;
        }
        else if (str[i]=='('){
            push(S,str[i]);
        }
        else if (i>0 && str[i-1]=='('){
            push(S,str[i]);
        }
        else if (str[i]==')'){
            while(S->arr[S->top]!='('){
                ans[j]=pop(S);
                j++;                
            }
            pop(S);
        }
        else if (stackempty(S)){
            push(S,str[i]);
        }
        else if (precedence(str[i])<=precedence(S->arr[S->top])){
            while(precedence(str[i])<=precedence(S->arr[S->top]) && !stackempty(S)){
                ans[j]=pop(S);
                j++;
            }
            push(S,str[i]); 
        }
        else {
            push(S,str[i]);
        }
    }
    while (!stackempty(S)){
        ans[j]=S->arr[S->top];
        j++;
        S->top--;
    }
    ans[j]='\0';
    printf("%s\n",ans);
}

int main(){
    struct Stack * S=malloc(sizeof(struct Stack));
    S->arr=calloc(100000,sizeof(char));
    S->top=-1;
    int n;
    char s[100000];
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        infixtopostfix(s,S);
    }
}