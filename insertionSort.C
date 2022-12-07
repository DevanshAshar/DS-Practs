#include<stdio.h>
void main()
{
    int a[100],i,j,n,key,temp;
    printf("enter no. of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter a no. ");
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=a[i];
        while(key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nSorted Array\n");
    for(i=0;i<n;i++)
    printf("%d",a[i]);
}
