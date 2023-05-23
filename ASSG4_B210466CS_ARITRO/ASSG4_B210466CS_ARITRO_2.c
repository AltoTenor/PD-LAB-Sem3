#include <stdio.h>
#define EL printf("\n");
#define printi(a) printf("%d\n",a);


void max_heapify(int arr[],int i,int n,int *c){
    int l= 2*i+1;
    int r=2*i+2;
    int largest,temp;
    // if (l<n) (*c)++;
    // if (r<n) (*c)++;
    if (l<n && arr[l]>arr[i]){
        largest=l;
    }
    else largest=i;

    if (r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if (largest!=i) {
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        max_heapify(arr,largest,n,c);
    }
    
}

void BuildMaxHeap(int arr[],int n,int *c){
    for (int i=n/2;i>=0;i--){
        max_heapify(arr,i,n,c);

    }
}
void heapsort(int arr[],int n,int *c){
    BuildMaxHeap(arr,n,c);
    int temp;
    for(int i=n-1;i>0;i--){
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        max_heapify(arr,0,i,c);
    }
}


int main(){
    int n;
    int c=0;
    int *ptrc=&c;
    scanf("%d",&n);
    int a[n+1];
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    heapsort(a,n,ptrc);
    for (int j=0;j<n;j++) printf("%d ",a[j]);
    EL
    printf("%d ",c);
}