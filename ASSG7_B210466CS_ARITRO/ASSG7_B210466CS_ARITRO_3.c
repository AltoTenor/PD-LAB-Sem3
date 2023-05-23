#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int *arr;
    int top;
};

int pop(struct Stack * S){
    int temp=S->arr[S->top];
    S->top--;
    return temp;
}

void push(struct Stack * S,int x){
    S->top++;
    S->arr[S->top]=x;
}

int stackempty(struct Stack * S){
    if (S->top==-1) return 1;
    else return 0;
}

int sizestr(char str[]){
    int c=0;
    for (int i=0;str[i]!='\0';i++)c++;
    return c;
}
 

int arraytodec(int num[],int j)
{
    int ans=0;
    int temp=j;
    while(temp--){
        ans*=10;
        ans+=num[j-temp-1];
        // printf("%d \n",ans);
    }
    return ans;
}

int  evaluatepostfix(char str[],struct Stack *S){
    int sz=sizestr(str);
    int res=0;
    for (int i=0;i<sz;i++){
        if (str[i]==' ') continue;

        else if (str[i]>='0' && str[i]<='9'){
            int num[100];
            int j;
            for (j=0;str[i]!=' ';i++,j++){
                num[j]=str[i]-'0';
            }
            int answer=arraytodec(num,j);
            
            push(S,answer);


        }

        else if (str[i]=='+'){
            res=pop(S)+pop(S);
            push(S,res);
        }
        else if (str[i]=='-'){
            int a=pop(S);
            int b=pop(S);
            res=b-a;
            push(S,res);
        }
        else if (str[i]=='*'){
            res=pop(S)*pop(S);
            push(S,res);
        }
        else if (str[i]=='/'){
            int a=pop(S);
            int b=pop(S);
            res=b/a;
            push(S,res);
        }

    }
    return res;

}

int main(){
    struct Stack * S=malloc(sizeof(struct Stack));
    S->arr=calloc(10000,sizeof(int));
    S->top=-1;
    int n;
    
    scanf("%d\n",&n);
    while(n--){
        char c[10000];
        S->arr=calloc(10000,sizeof(int));
        fgets(c,10000,stdin);
        printf("%d\n",evaluatepostfix(c,S));
    }
}