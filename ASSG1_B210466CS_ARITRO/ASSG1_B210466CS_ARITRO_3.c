#include <stdio.h>

char toupper1(char x){
	if (x>96){
		return x-32;
	}
	else return x;
}

int slen(char s[]){
	int c=0;
	for (int i=0;s[i]!='\0';i++) c++;
	return c;
}

int main(){
	char s[1000000];
	scanf("%s",s);
	int	n=slen(s);
	for (int i=0;i<n;i++){
		s[i]=toupper1(s[i]);
	}
	int fl=1;
	for (int i=0;i<n/2;i++){
		if (s[i]!=s[n-i-1]){
			fl=0;
			break;
		}
	}
	if (fl==1) printf("YES");
	else printf("NO");
	
	
}
