//Deleting Tree

#include<stdio.h>
#include"tree.h"

void inorder(struct node * r)
{
    if(r==NULL)return;

    printf("%d ",r->data);
    inorder(r->left);
    inorder(r->right);
}
void Tdel(struct node *r)
{
    if(r==NULL)return;

    Tdel(r->left);
    Tdel(r->right);
    free(r);
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
    Tdel(root);
    printf("\nTree Deleted");
}
