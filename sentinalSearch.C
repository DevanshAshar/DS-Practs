#include<stdio.h>
void main()
{
    int i,search,a[100],n,last;
    printf("Enter number of elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter a no. ");
        scanf("%d",&a[i]);
    }
    printf("Enter search value ");
    scanf("%d",&search);
    last=a[n-1];
    a[n-1]=search;
    i=0;
    while(a[i]!=search)
    i++;
    a[n-1]=last;
    if(i<n-1 || a[n-1]==search)
    printf("Element found at pos %d",i+1);
    else
    printf("element not found");
}
