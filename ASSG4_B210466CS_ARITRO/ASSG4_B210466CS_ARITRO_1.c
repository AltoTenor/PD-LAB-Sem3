#include <stdio.h>
#define EL printf("\n");
#define printstr(a) printf("Name A: %s\n",a);
#define printstr1(a) printf("Name B: %s\n",a);
#define printi(a) printf("%d\n",a);

struct S{
    char name[40];
    int marks; 
};

void assign(char b[],char a[]){
    int i;
    for (i=0;a[i]!='\0';i++) b[i]='\0';
    for (i=0;a[i]!='\0';i++) b[i]=a[i];
    b[i]='\0';
}
int check(char b[],char a[]){
    int i;
    for (i=0;a[i]!='\0' && b[i]!='\0';i++){
        if (a[i]!=b[i]){
            return 0;
        }
    }
    return 1;

}


void partition( struct S arr[],int low,int high,int ind){
    int x=arr[ind].marks;
    int i=low-1;
    int temp;
    char temps[40];
    for (int j=low;j<high;j++){
        if (arr[j].marks<=x && j!=ind){
            i++;
            

            temp=arr[j].marks;
            arr[j].marks=arr[i].marks;
            arr[i].marks=temp;


            assign(temps,arr[j].name);
            assign(arr[j].name,arr[i].name);
            assign(arr[i].name,temps);
            if (i==ind){
                ind=j;
            }
        }
    }
    temp=arr[ind].marks;
    arr[ind].marks=arr[i+1].marks;
    arr[i+1].marks=x;

    assign(temps,arr[ind].name);
    assign(arr[ind].name,arr[i+1].name);
    assign(arr[i+1].name,temps);
}

int main(){
    int n;
    scanf ("%d",&n);
    struct S arr[n];
    for (int l=0;l<n;l++){
        scanf("%s",arr[l].name);
        scanf("%d",&arr[l].marks);
    }
    char CR[40];
    scanf("%s",CR);
    int ind;
    for (int i=0;i<n;i++){
        if (check(arr[i].name,CR)==1) ind=i;
    }
    // printi(ind);
    partition(arr,0,n,ind);
    for (int l=0;l<n;l++){ //To print
        printf("%s ",arr[l].name);
    }
}