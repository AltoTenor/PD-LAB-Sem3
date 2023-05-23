#include <stdio.h>

int binarysearch(int arr[],int lower,int upper,int x){
    if (upper>=lower){
        int mid=(upper+lower)/2;
        if (arr[mid]==x) return mid;
        else if (arr[mid]>x) return binarysearch(arr,lower,mid-1,x);
        else if (arr[mid]<x) return binarysearch(arr,mid+1,upper,x);
    }
    else return -1;
}

int linearsearch(int arr[],int n,int x){
    int count=0;
    for (int i=0;i<n;i++)
        if (arr[i]>x) {
            printf("%d ",i);
            count++;
        }
    if (count==0) printf("-1");
}

int main(){
    int n,t;
    scanf("%d",&n);
    scanf("%d",&t);
    int arr[n];
    for (int i=0;i<n;i++) scanf("%d",arr+i);
    int b=binarysearch(arr,0,n-1,t);
    printf("%d\n",b);
    if (b==-1) printf("-1");
    else linearsearch(arr,n,arr[b]);

}