#include<stdio.h>
#define max 100
int front=-1,rear=-1,a[max];
void insert(int val)
{
    if(rear==max-1)
    printf("Overflow");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    rear++;
    a[rear]=val;
}
int del()
{
    if(front==-1 && rear==-1)
    return -1;
    else
    {
        int d=a[front];
        front++;
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
        return d;
    }
}
int isEmpty()
{
    if(front==-1 && rear==-1)
    return -1;
    else
    return a[front];
}
void main()
{
    int i,j,n;
    printf("Enter size of matrix ");
    scanf("%d",&n);
    int v[n];
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter 0/1 for (%d,%d) ",i,j);
            scanf("%d",&arr[i][j]);
        }    
    }
    for(i=0;i<n;i++)
    v[i]=0;
    printf("\nAdjacency Matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }    
        printf("\n");
    }
    printf("enter vertex ");
    scanf("%d",&i);
    printf("%d ",i);
    v[i]=1;
    insert(i);
    while(isEmpty()!=-1)
    {
        int node=del();
        for(int i=0;i<n;i++)
        {
            if(arr[i][node]==1 && v[i]==0)
            {
                v[i]=1;
                printf("%d ",i);
                insert(i);
            }
        }
    }
}
