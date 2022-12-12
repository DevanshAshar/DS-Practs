#include<stdio.h>
#define MAX 10
void merge(int a[],int beg,int mid,int end)
{
    int i,j,k,temp[MAX],index;
    i=beg;
    j=mid+1;
    index=beg;
    while(i<=mid && j<=end)
    {
        if(a[i]<a[j])
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
    a[k]=temp[k];
}
void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void main()
{
    int i,a[MAX],n;
    printf("Enter number of terms ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter term %d ",i+1);
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("Sorted array\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
