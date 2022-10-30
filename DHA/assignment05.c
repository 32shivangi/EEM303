//convert an array of integer to binary search tree

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

void putval(int ele,struct node *r)
{
    if(ele<r->data)
    {
        if(r->left==NULL)
        {
               LC(r,ele);
                return;
        }
        putval(ele,r->left);
    }
    else
    {
        if(r->right==NULL)
        {
             RC(r,ele);
                return;
        }
        putval(ele,r->right);
    }
}
int f=-1;

struct node * arrange(int a[],struct node* p,int r)
{
  if(f==-1)
  {
      f=0;
      p=create(a[0]);
  }
  else if(f==r)
  {
       f=r=-1;
      return p;
  }
      ++f;
      putval(a[f],p);
      arrange(a,p,r);

}
main()
{
    int a[10];
    int i=0;
   char ch;
    do
    {

    printf("enter element:");
    fflush(stdin);
    scanf("%d",&a[i]);
    i=i+1;
    printf("Do you wanna enter more elements(y/n):");
    fflush(stdin);
    scanf("%c",&ch);

    }while(ch=='y');

    struct node * root=arrange(a,root,i-1);

     inorder(root);
}
