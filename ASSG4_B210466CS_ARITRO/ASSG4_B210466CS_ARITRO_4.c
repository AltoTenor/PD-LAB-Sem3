#include <stdio.h>



void max_heapify(int arr[],int i,int n){
    int l= 2*i+1;
    int r=2*i+2;
    int smallest,temp,temp1;
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

int search(int arr[],int x,int n){
    for(int i=0;i<n;i++) if (arr[i]==x) return i;
    return -1;
}

void BuildMaxHeap(int arr[],int n){
    for (int i=n/2;i>=0;i--){
        max_heapify(arr,i,n);
    }
}
void heapsort(int arr[],int n){
    BuildMaxHeap(arr,n);
    int temp,temp1;
    for(int i=n-1;i>0;i--){
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        n--;
        max_heapify(arr,0,n);
    }
}

int indprint(int freq[],int used[],int freq1,int len){
    for(int i=0;i<len;i++) if (used[i]==0 && freq[i]==freq1){
        used[i]=1;
        return i;
    }
}

int main(){
    int n,temp,k;
    scanf("%d",&n);
    int arr[n];
    int freq[n];
    int freqcopy[n];
    int used[n];
    for(int i=0;i<n;i++) used[i]=0;
    int len=0;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        int ind=(search(arr,temp,len));
        if (ind==-1){
            arr[len]=temp;
            freq[len]=1;
            freqcopy[len]=1;
            len++;
        }
        else {
            freq[ind]++;
            freqcopy[ind]++;
        }
    }
    scanf("%d",&k);

    heapsort(freq,len);

    // for (int i=0;i<len;i++){
    //     printf("Sorted Freq:%d Org Freq: %d Arr: %d\n",freq[i],freqcopy[i],arr[i]);
    // }

    for (int i=0,j=len-1;i<k;i++,j--){
        printf("%d ",arr[indprint(freqcopy,used,freq[j],len)]);
    }
}