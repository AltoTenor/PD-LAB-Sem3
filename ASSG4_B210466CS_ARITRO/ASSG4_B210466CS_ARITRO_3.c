#include <stdio.h>
#define EL printf("\n");
#define printi(a) printf("%d\n",a);

void max_heapify(float arr[],int i,int n){
    int l= 2*i+1;
    int r=2*i+2;
    int smallest;
    float temp;
    if (l<n && arr[l]>arr[i]){
        smallest=l;
    }
    else smallest=i;
    if (r<n && arr[r]>arr[smallest]){
        smallest=r;
    }
    if (smallest!=i) {
        temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        max_heapify(arr,smallest,n);
    }
    
}

void BuildMaxHeap(float arr[],int high){
    for (int i=(high)/2;i>=0;i--){
        max_heapify(arr,i,high);
    }
}
int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    float arr[n/k][k];
    for (int i=0;i<n/k;i++){
        for (int j=0;j<k;j++){
            scanf("%f",&arr[i][j]);
            // printf("%d %d\n",i,j);
        }
    }
    for (int i=0;i<n/k;i++){
        BuildMaxHeap(arr[i],k);
    }
    for (int i=0;i<n/k;i++){
        printf("%.2f ",arr[i][0]);
    }

}