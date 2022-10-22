//FInding maximum element in binary tree

#include<stdio.h>
#include<limits.h>
#include"tree.h"

void inorder(struct node * r)
{
    if(r==NULL)return;

    printf("%d ",r->data);
    inorder(r->left);
    inorder(r->right);
}
int max=INT_MIN;

void TMAX(struct node *r)
{
    if(r==NULL)return;

    TMAX(r->left);
    TMAX(r->right);

    max=(max>r->data)?max:r->data;
}

main()
{
    struct node *root;
    root=create(1);
    LC(root,2);
    RC(root,3);
    LC(root->left,4);
    RC(root->left,5);
     LC(root->right,6);
    RC(root->right,7);
    printf("TREE: ");
    inorder(root);
    TMAX(root);
    printf("\nMaximum element:%d ",max);
}
