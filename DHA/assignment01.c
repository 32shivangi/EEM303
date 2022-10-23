#include<stdio.h>
#include<stdlib.h>
int flag=0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int val)
{
  struct node *p=(struct node *)malloc(sizeof(struct node));;

  p->data=val;
  p->left=NULL;
  p->right=NULL;

  return p;
}

struct node *LC(int val, struct node *r)
{
    struct node *p=create(val);
    r->left=p;
}

struct node *RC(int val, struct node *r)
{
    struct node *p=create(val);
    r->right=p;
}

void inorder(struct node *r)
{
    if(r==NULL)return;

    inorder(r->left);
    printf("%d->",r->data);
    inorder(r->right);
}
void ispresent(int ele,struct node *r)
{
    if(r==NULL)return;

    ispresent(ele,r->left);
    if(r->data==ele)
    {
        flag=1;
        printf("Element Found");
        exit(1);
    }

    ispresent(ele,r->right);

}

void main()
{
    struct node *root;
    root=create(1);
    LC(2,root);
    RC(3,root);
    LC(4,root->left);
    RC(5,root->left);
    LC(6,root->right);
    RC(7,root->right);

    inorder(root);
    int x;
    printf("\nEnter element to search:");
    scanf("%d",&x);
    ispresent(x,root);
    if(flag==0)
    {
        printf("Element Not Found");
    }
}

