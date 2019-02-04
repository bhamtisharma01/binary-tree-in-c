#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct btree
{
    int data;
    int hd; /*horizontal distance*/
    struct btree* left;
    struct btree* right;
}btree;

btree* initializeNode(int d, int hdist)
{
    btree* nn = (btree*)malloc(sizeof(btree));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    nn->hd = hdist;
    return nn;
}
int res[200];

btree* createTree(btree* root, int d, int hd)
{
    if( root == NULL)
    {
        return initializeNode(d, hd);
    }

    if( d  < root-> data)
    {

        root->left  = createTree(root->left, d, hd-1);
    }
    else
        root->right  = createTree(root->right, d,hd+1);

    return root;
}

struct hash
{
  int data;
  int height;
};
void fun(struct hash*h[100],struct btree*root,int i,int height)
{
  if(root==NULL)
    return;
  else if(h[i+50]->data==-1 && h[i+50]->height==-1)
  {
    h[i+50]->data=root->data;
    h[i+50]->height=height;
  }
  else if(h[i+50]->height<=height)
  {
    h[i+50]->data=root->data;
    h[i+50]->height=height;
  }
  fun(h,root->left,i-1,height+1);
  fun(h,root->right,i+1,height+1);
}
void bottomView( btree* root,  int* l, int* r)
{
  if(root==NULL)
    return;
  struct hash*h[100];
  for(int i=0;i<100;i++)
  {
    h[i]=(struct hash*)malloc(sizeof(struct hash));
    h[i]->data=-1;
    h[i]->height=-1;
  }
  fun(h,root,0,0);
  for(int i=0;i<100;i++)
  {
    if(h[i]->data!=-1)
      printf("%d ",h[i]->data);
  }
}

int main()
{
memset(res,0,100*sizeof(res[0]));
    btree* root = NULL;

    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        root = createTree(root, arr[i],0);
    }
int left=100,right=100;
bottomView(root,&left,&right);

/*for(i=left;i<=right;i++)
    {
    printf("%d ", res[i]);
    }*/

}
