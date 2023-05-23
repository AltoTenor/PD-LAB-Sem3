#include <stdio.h>
#define ll long long
ll power(ll a,ll e){
	ll m=1;
	for(ll i=0;i<e;i++) m*=a;
  	return m;	
}

int main(){
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	ll sum=0;
	ll temp=0;
	while(n){
		temp=n%10;
		sum+=power(temp,x);
		n=n/10;
	}
	printf("%lld",sum);
	return 0;

}
