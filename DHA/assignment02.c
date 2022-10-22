//Finding size of binary tree

#include<stdio.h>
#include"tree.h"
int c=0;
void Tsize(struct node *r)
{
    if(r==NULL)return;

    Tsize(r->left);
    Tsize(r->right);
    c++;
}
void inorder(struct node * r)
{
    if(r==NULL)return;

    printf("%d ",r->data);
    inorder(r->left);
    inorder(r->right);
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
    Tsize(root);
    printf("\nSize of tree:%d",c);
}
