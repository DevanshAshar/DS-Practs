#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int totalNodes,leafNodes;
struct node*createnode(int val)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    return temp;
}
struct node *insert(struct node*naya,int val)
{
    struct node*temp;
    if(naya==NULL)
    {
        naya=createnode(val);
    }
    else if(val<naya->data)
    {
        naya->left=insert(naya->left,val);
    }
    else
    {
       naya->right=insert(naya->right,val);
    }
    return naya;
}
void countNodes(struct node* root) {
    if (root != NULL) {
        totalNodes++;
        if (root->left == NULL && root->right == NULL) {
            leafNodes++;
        }
        countNodes(root->left);
        countNodes(root->right);
    }
}
void printInOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}
void main() {
    int ch,val;
    struct node *root;
    do
    {
        printf("\n1)Insert\n2)Count Nodes\n3)Exit\nEnter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value ");
                scanf("%d",&val);
                root=insert(root,val);
                printInOrder(root);
                break;
            case 2:totalNodes=0,leafNodes=0;
                    countNodes(root);
                    printf("Total nodes=%d\nLeaf Nodes=%d",totalNodes,leafNodes);
                    break;
            case 3:printf("Bye");
                    break;
            default:printf("Invalid choice");
        }
    }while(ch!=4);
}
