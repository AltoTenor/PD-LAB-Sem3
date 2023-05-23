#include <stdio.h>

void read_and_store(int A[],int n){
    for (int i=0;i<n;i++) scanf("%d",A+i);
    A[n]='\0';
}

void print(int A[],int n){
    for ( int i=0;i<n;i++) printf("%d ",A[i]);
    printf("\n");
}

int digit_sum(int n){
    int sum=0;
    int x=n;
    while(x){
        sum+=x%10;
        x=x/10;
    }
    return sum;
}

void digit_sort(int A[],int n){
    float key;
    int i;
    for (int j=1;j<n;j++){
        key=A[j];
        i=j-1;
        while( i>=0 && digit_sum(A[i])>digit_sum(key) ){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

int main(){
    int arre[10000];
    for ( int i=0;i<10000;i++) arre[i]='\0';
    int n,ds;
    char option='x';
    while(option!='t'){
        scanf("%c",&option);
        if (option=='r'){
            scanf("%d",&n);
            read_and_store(arre,n);
        }
        else if (option=='p'){
            print(arre,n);
        }
        else if (option=='d'){
            int i;
            scanf("%d",&i);
            ds=digit_sum(arre[i]);
            printf("%d\n",ds);
        }
        else if (option=='s'){
            digit_sort(arre,n);
        }
    }
    printf("-1");
}