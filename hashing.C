#include<stdio.h>
void hash(int h[],int i,int k,int n)
{
    int j;
    j=(k%n+i)%n;
    if(i>n)
    printf("Hash table full\n");
    else if(h[j]==-1)
    h[j]=k;
    else if(h[j]!=-1)
    hash(h,i+1,k,n);
    else
    printf("Sorry");
}
void main()
{
    int i,h[100],size,ch,k;
    printf("Enter size of hash table ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    h[i]=-1;
    do
    {
        printf("Enter key value ");
        scanf("%d",&k);
        hash(h,0,k,size);
        printf("Enter 1 to continue ");
        scanf("%d",&ch);
    }while(ch==1);
    for(i=0;i<size;i++)
    {
        if(h[i]!=-1)
        printf("%d ",h[i]);
        else
        printf("NULL ");
    }
}
