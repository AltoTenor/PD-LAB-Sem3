#include <stdio.h>

int findchar(char s[],char a){
    for (int i=0;s[i]!='\0';i++)
        if (s[i]==a) return i;
    return -1;
}



int main(){
    char str[1002];
    char key[1002];
    int freq[1002];
    for (int i=0;i<1002;i++){
        key[i]='\0';
        freq[i]='\0';
        str[i]='\0';
    }
    scanf("%s",str);
    int ind,k=0;
    for (int i=0;str[i]!='\0';i++){
        ind=findchar(key,str[i]);
        if ( ind==-1 ){
            key[k]=str[i];
            freq[k]=1;
            k++;
        }
        else{
            freq[ind]++;
        }
    }
    long long int ans=1;
    for (int i=0;key[i]!='\0';i++) {
        ans*=freq[i];
    }
    printf("%lld",ans);
}