#include <stdio.h>

void merge(int A[],int B[],int m,int n,int ans[]){
    int j=0,k=0;
    for (int i=0;i<m+n;i++){
        if (A[j]<B[k]){
            ans[i]=A[j];
            j++;
        }
        else if (A[j]>B[k]){
            ans[i]=B[k];
            k++;
        }
        else{
            ans[i]=A[j];
            i++;
            ans[i]=B[k];
            j++;
            k++;
        }
    }
}

int BIS(int arr[],int low,int high,int x){
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
    int n,m,t;
    scanf("%d",&m);
    scanf("%d",&n);
    int A[m+1], B[n+1],ans[m+n];
    for (int i=0;i<m;i++) scanf("%d",A+i);
    A[m]=__INT_MAX__;
    B[n]=__INT_MAX__;
    for (int i=0;i<n;i++) scanf("%d",B+i);
    scanf("%d",&t);
    merge(A,B,m,n,ans);
    int pos=BIS(ans,0,m+n,t);
    printf("%d",pos);
}