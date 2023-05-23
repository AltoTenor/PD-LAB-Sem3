#include <stdio.h>

int main(){
	int n,x;
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++) scanf("%d",arr+i);
	scanf("%d",&x);
	x=x%n;
	if (x==0){
		int i=0;
		for (;i<n-1;i++) printf("%d ",arr[i]);
		printf("%d",arr[i]);
	}
	else{
		for (int i=x;i<n;i++) printf("%d ",arr[i]);
		int i=0;
		for (;i<x-1;i++) printf("%d ",arr[i]);
		printf("%d",arr[i]);
	}
	return 0;
}
