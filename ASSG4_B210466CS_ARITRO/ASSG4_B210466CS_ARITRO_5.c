#include <stdio.h>
#define printi(a) printf("Print: %d\n",a)


int n=0;
void heap_increase_key(int arr[],int i,int key){
    arr[i]=key;
    int temp;
    while(i>0 && arr[(i-1)/2]>arr[i]){
        temp=arr[i];
        arr[i]=arr[ (i-1)/2];
        arr[ (i-1)/2]=temp;
        i=(i-1)/2;
    }
}

void min_heapify(int arr[],int i){
    int l= 2*i+1;
    int r=2*i+2;
    int smallest,temp,temp1;
    if (l<n && arr[l]<arr[i]){
        smallest=l;
    }
    else smallest=i;
    if (r<n && arr[r]<arr[smallest]){
        smallest=r;
    }
    if (smallest!=i) {
        temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        min_heapify(arr,smallest);
    }
    
}

void insert(int q[],int k){
    heap_increase_key(q,n,k);
    n++;
    
}

int extract_new_process(int q[]){
    if (n<1){
        return -1;
    }
    int min=q[0];
    q[0]=q[n-1];
    n--;
    min_heapify(q,0);
    return min;
}

int get_new_process(int q[]){
    if (n<1) return -1;
    else return q[0];
}

int search(int arr[],int x){
    for (int i=0;i<n;i++){
        if (arr[i]==x) return i;
    }
    return -1;
}
void ChangepriorityQueue(int q[],int k,int x){
    heap_increase_key(q,search(q,k),x);
}

void display(int q1[]){
    int temp;
    temp=n;
    for (int i=0;i<temp;i++){
        printf("%d ",extract_new_process(q1));
    }
    n=temp;
}

void display1(int q[]){
    for (int i=0;i<n;i++) printf("%d ",q[i]);
}

void copy(int q[],int q1[]){
    for (int i=0;i<n;i++) q1[i]=q[i];
}

int main(){
    int q[1001];
    int q1[1001];
    char op='x';
    int temp;
    while(op!='s'){
        scanf("%c",&op);
        if (op=='i'){
            int temp;
            scanf("%d",&temp);
            insert(q,temp);
            // for (int i=0;i<n;i++) printi(q[i]);
        }
        
        else if(op=='e'){
            printf("%d\n",extract_new_process(q));

        }
        else if (op=='m'){
            printf("%d\n",get_new_process(q));
        }
        else if(op=='c'){
            int old,new;
            scanf("%d",&old);
            scanf("%d",&new);
            ChangepriorityQueue(q,old,new);
        }
        else if(op=='d'){
            copy(q,q1);
            // for (int i=0;i<n;i++) printi(q1[i]);
            display(q1);
            printf("\n");
        }
        
    }
}