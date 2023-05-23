#include <stdio.h>

void InSort(float arr[],int n){
    float key;
    int i;
    for (int j=1;j<n;j++){
        key=arr[j];
        i=j-1;
        while( i>=0 && arr[i]>key ){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}

int BIS(float arr[],int low,int high,float x){
    int mid=(low+high)/2;
    while(low<=high){
        mid=(low+high)/2;
        if (arr[mid]==x) return mid;
        else if (arr[mid]>x) high=mid-1;
        else if (arr[mid]<x ) low=mid+1;
    }
    return -1;
}


int main(){
    int n;
    scanf("%d",&n);
    float A[n];
    float Acopy[n];
    for ( int i=0;i<n;i++) scanf("%f",A+i);
    for ( int i=0;i<n;i++) Acopy[i]=A[i];
    InSort(A,n);
    for (int i=0;i<n;i++){
        printf("%d ",BIS(A,0,n,Acopy[i]));
    }
}