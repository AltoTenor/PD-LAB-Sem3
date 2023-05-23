#include <stdio.h>

int delete(int arr[],int n,int x){
    int i=0;
    for (int k=0;k<n;i++,k++){
        while (arr[k]==x){
            k++;
            if (k==n) return i;
        }
        arr[i]=arr[k];
    }
    return i;
}

int secondmax(int arr[],int n){
    int max=-1001;
    int max2=-1001;
    for (int i=0;i<n;i++) if (arr[i]>max) max=arr[i];
    for (int i=0;i<n;i++) if (arr[i]>max2 && arr[i]!=max) max2=arr[i];
    return max2;

}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) scanf("%d",arr+i);
    int x=delete(arr,n,secondmax(arr,n));
    for (int i=0;i<x-1;i++) printf("%d ",arr[i]);
    printf("%d",arr[x-1]);

}