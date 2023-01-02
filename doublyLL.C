#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head;
struct node *createnode()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert(int val)
{
    struct node *n,*temp;
    n=createnode();
    n->data=val;
    if(head==NULL)
    head=n;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=n;
        n->prev=temp;
    }
}
void del(int val)
{
    struct node *temp,*ntemp;
    temp=head;
    if(head==NULL)
    printf("LL is empty");
    else
    {
        if(head->data==val)
        {
            if(head->next==NULL)
            head=NULL;
            else
            {
                head=head->next;
                head->prev=NULL;
                free(temp);
            }
        }
        else
        {
            ntemp=temp->next;
            while(ntemp->data!=val)
            {
                ntemp=ntemp->next;
                temp=temp->next;
            }
            if(ntemp->next==NULL)
            {
                free(ntemp);
                temp->next=NULL;
            }
            else
            {
                free(ntemp);
                ntemp=ntemp->next;
                temp->next=ntemp;
                ntemp->prev=temp;
            }
        }
    }
}
void display()
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
void main()
{
    int ch,val;
    do
    {
        printf("1)Insert\n2)Delete\n3)Display\n4)Exit\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value");
                    scanf("%d",&val);
                    insert(val);
                    break;
            case 2:printf("Enter value");
                    scanf("%d",&val);
                    del(val);
                    break;
            case 3:display();
                    break;
            case 4:printf("Thank you");
                    break;
            default:printf("Invalid Input");
        }
    }while(ch!=4);
}
