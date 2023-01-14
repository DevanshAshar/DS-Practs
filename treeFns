#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode*createnode(int val)
{
    struct TreeNode*temp;
    temp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=val;
    return temp;
}
struct TreeNode *insert(struct TreeNode*naya,int val)
{
    struct TreeNode*temp;
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
struct TreeNode* copyTree(struct TreeNode* root) {
    if (root == NULL) {
        return ;
    }
    struct TreeNode* newRoot =createnode(root->data);
    newRoot=insert(newRoot,root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

void mirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    mirrorTree(root->left);
    mirrorTree(root->right);
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void printInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void main() {
    
    int ch,val;
    struct TreeNode* root=NULL,*copy=NULL;
    do
    {
    printf("\n1)Insert\n2)Copy\n3)Mirror\n4)DisplayCopy\n5)Exit\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter value ");
                scanf("%d",&val);
                root=insert(root,val);
                printInOrder(root);
                break;
        case 2:copy=copyTree(root);
                break;
        case 3:mirrorTree(root);
                printInOrder(root);
                break;
        case 4: printInOrder(copy);
                break;
        case 5:printf("Thank you ");
                break;
        default:printf("Invalid choice ");
        
    }
    }while(ch!=5);
}
