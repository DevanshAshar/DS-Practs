#include<stdio.h>
int partition(int a[],int left,int right)
{
    int pivot,temp,flag=0;
    pivot=left;
    while(flag!=1)
    {
        while(a[pivot]<=a[right] && right!=pivot)
        right--;
        if(pivot==right)
        flag=1;
        else if(a[pivot]>a[right])
        {
            temp=a[pivot];
            a[pivot]=a[right];
            a[right]=temp;
            pivot=right;
        }
        if(flag!=1)
        {
            while(a[pivot]>=a[left] && left!=pivot)
            left++;
            if(pivot==left)
            flag=1;
            else if(a[pivot]<a[left])
            {
                temp=a[pivot];
                a[pivot]=a[left];
                a[left]=temp;
                pivot=left;
            }
        }
    }
    return pivot;
}
void quicksort(int n[],int left,int right)
{
    int piv;
    if(left<right)
    {
    piv=partition(n,left,right);
    quicksort(n,left,piv-1);
    quicksort(n,piv+1,right);
    }
}
void main()
{
    int a[100],i,j,n;
    printf("enter no. of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter a no. ");
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}
