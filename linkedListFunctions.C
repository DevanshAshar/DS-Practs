#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*headc,*heads;
struct node *createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
void insert(int val)
{
    struct node *n,*temp;
    n=createnode();
    n->data=val;
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=n;
        n->next=NULL;
    }
}
void display(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    printf("LL is empty");
    else
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
struct node *rev(struct node *temp)
{
    struct node *prev=NULL,*curr=temp,*forward=NULL;
    if(temp==NULL)
    {
        printf("LL is empty ");
        return;
    }
    else if(temp->next==NULL)
    return temp;
    else
    {
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
}
void del(int val)
{
    struct node *temp,*prev=head;
    temp=head->next;
    if(head->data==val)
    {
        head=head->next;
        prev->next=NULL;
        free(prev);
    }
    else
    {
        while(temp->data!=val)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
}
struct node *copy(struct node *temp)
{
    struct node *n,*temp1,*headcp,*prev;
    if(temp==NULL)
    printf("LL is empty");
    else
    {
        temp1=createnode();
        temp1->data=temp->data;
        temp1->next=NULL;
        headc=temp1;
        temp=temp->next;
        while(temp!=NULL)
        {
            n=createnode();
            n->data=temp->data;
            temp1->next=n;
            temp1=n;
            temp=temp->next;
        }
    }
    return headc;
}
struct node *concat(struct node *temp1,struct node *temp2)
{
    while(temp1->next!=NULL)
    temp1=temp1->next;
    temp1->next=temp2;
    return temp1;
}
struct node *split(struct node *temp,int n)
{
    int ct=0;
    while(ct<n-1 && temp!=NULL)
    {
        temp=temp->next;
        ct++;
    }
    heads=temp->next;
    temp->next=NULL;
}
int totalNodes(struct node *temp)
{
    int ct=0;
    while(temp!=NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
}
void main()
{
    int ch,val,k;
    do
    {
        printf("\n1)Insert\n2)Reverse\n3)Copy\n4)DisplayCopy\n5)Concat\n6)Split\n7)Total nodes\n8)Display\n9)Delete\n10)Exit\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value ");
                    scanf("%d",&val);
                    insert(val);
                    break;
            case 2:head=rev(head);
                    break;
            case 3:headc=copy(head);
                    break;
            case 4:display(headc);
                    break;
            case 5://ideally dusra LL banana padega but check karne copy wala hi daal diya
                    concat(head,headc);
                    display(head);
                    break;
            case 6:printf("After how many split? ");
                    scanf("%d",&val);
                    display(head);
                    split(head,val);
                    printf("\nAfter Split\n");
                    display(head);
                    printf("\n");
                    display(heads);
                    break;
            case 7:k=totalNodes(head);
                    printf("\nTotal nodes are %d",k);
                    break;
            case 8:display(head);
                    break;
            case 9:if(head==NULL)
                    printf("LL is empty");
                    else
                    {
                        printf("Enter value ");
                        scanf("%d",&val);
                        del(val);
                    }
                    break;
            case 10:printf("Thank you");
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=10);
}
