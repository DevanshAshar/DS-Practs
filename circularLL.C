#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node *head;
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
    head->next=head;
    }
    else
    {
        temp=head->next;
        while(temp->next!=head)
        temp=temp->next;
        temp->next=n;
        n->next=head;
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
            if(head->next==head)
            head=NULL;
            else
            {
                while(temp->next!=head)
                temp=temp->next;
                ntemp=head;
                head=head->next;
                temp->next=head;
                free(ntemp);
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
            if(ntemp->next==head)
            {
                free(ntemp);
                temp->next=head;
            }
            else
            {
                free(ntemp);
                ntemp=ntemp->next;
                temp->next=ntemp;
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
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
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
