#include<stdio.h>
void main()
{
    int a[100],i,j,n,min,temp;
    printf("enter no. of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter a no. ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}
