#include <stdio.h>

int comp(char a[],char b[]){
    int i=0;
    char temp1,temp2;
    while(a[i]!='\0' &&  b[i]!='\0'){
        
        if (a[i]>95) temp1=a[i];
        else temp1=a[i]+32;
        if (b[i]>95) temp2=b[i];
        else temp2=b[i]+32;

        if (temp1>temp2) {
            return 2;
        }
        else if (temp1<temp2) {
            return 1;
        }
        else{
            i++;
        }

    }
    if (a[i]=='\0' && b[i]!='\0') return 2;
    else if (a[i]!='\0' && b[i]=='\0') return 1;
    else return 0;
}

void assign(char a[],char b[]){
    int i;
    for (i=0;a[i]!='\0';i++) b[i]='\0';
    for (i=0;a[i]!='\0';i++) b[i]=a[i];
    b[i]='\0';
}

void merge(char arr[][100],int l,int mid,int r){
    char A[mid+1-l][100];
    char B[r-mid][100];
    int i;
    char max[]="";
    for (i=0;i<mid+1-l;i++){
        assign(arr[l+i],A[i]);
    }
    assign(max,A[mid+1-l]);

    for (i=0;i<r-mid;i++){
        assign(arr[mid+1+i],B[i]);
    }
    assign(max,B[r-mid]);

    int j=0,k=0;
    for (int i=l;i<r+1;i++){
        if (comp(A[j],B[k])==1){
            assign(A[j],arr[i]);
            j++;
        }
        else if (comp(A[j],B[k])==2){
            assign(B[k],arr[i]);
            k++;
        }
        else{
            assign(A[j],arr[i]);
            i++;
            assign(B[k],arr[i]);
            j++;
            k++;
        }
    }
}

void mergesort(char arr[][100],int l,int r){
    if (l<r){
        int mid=(r+l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    char names[n][100];

    for (int i=0;i<n;i++){
        fgets(names[i],100,stdin);
    }
    mergesort(names,0,n-1);
    for ( int i=0;i<n;i++) printf("%s",names[i]);
}
