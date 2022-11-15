//deleting an element form Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int flag=0;
struct node * ispresent(int ele,struct node *r)
{
    if(r==NULL)return;

    ispresent(ele,r->left);
    if(r->data==ele)
    {
        flag=1;
        printf("Element Found");
        return r;
    }

    ispresent(ele,r->right);

}

struct node *prev(struct node *root)
{
    if(root->left != NULL)root=root->left;
    else return (root->right);

    while(root->right)
    {
        root=root->right;
    }

    return root;
}
void del(int ele,struct node * root)
{
    struct node * r=(struct node *)malloc(sizeof(struct node));
     r = ispresent(ele,root);

     if(r->left == NULL && r->right == NULL)
     {
         free(r);
         return;
     }
     else
     {
         struct node * temp=(struct node *)malloc(sizeof(struct node));
         temp=prev(r);

         r->data=temp->data;

         del(temp->data,temp);
     }
}
main()
{
    int a[10]={12,3,8,7,14,10,15,9,17,11};
    int i=10,x;

    struct node * root=arrange(a,root,i-1);

     inorder(root);

     printf("\nEnter element to delete:");
     scanf("%d",&x);
       del(x,root);

    inorder(root);
}
