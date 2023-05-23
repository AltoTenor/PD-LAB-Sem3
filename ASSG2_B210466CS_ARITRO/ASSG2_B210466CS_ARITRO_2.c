#include <stdio.h>

int main (){
    int n,k;
    int arr[1005];
    int x;
    scanf("%d",&n);
    scanf("%d",&k);
    for (int i=0;i<n;i++) scanf("%d",arr+i);
    scanf("%d",&x);
    int m=n/k;
    int lower=0;
    int upper=1;
    int counter=0;
    while(m--){
        for (int i=lower;i<k*upper;i++){
            if (arr[i]==x){
                counter++;
                break;
            } 
        }
        lower=k*upper;
        upper++;
    }
    printf("%d",counter);
}