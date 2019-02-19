#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* left;
	struct node* right;
	int height;
};
int max(int a,int b)
{
	return(a>b)?a:b;
}
int height(struct node* n)
{
	if(n==NULL)
	return 0;
	return n->height;
}
struct node* newNode(int d)
{
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->key=d; 
    node->left=NULL; 
    node->right=NULL; 
    node->height=1; 
    return(node); 
}
struct node* rightRotate(struct node*y)
{
	struct node*x=y->left;
	struct node*t2=x->right;
	
	x->right=y;
	y->left=t2;
	
	y->height=1+max(height(y->left),height(y->right));
	x->height=1+max(height(x->left),height(x->right));
	
	return x;
}

struct node* leftRotate(struct node*x)
{
	struct node*y=x->right;
	struct node*t2=y->left;
	
	y->left=x;
	x->right=t2;
	
	x->height=1+max(height(x->left),height(x->right));
	y->height=1+max(height(y->left),height(y->right));
	
	return y;
}
int balance(struct node*n)
{
	if(n==NULL)
	return 0;
	return height(n->left)-height(n->right);
}
struct node* insert(struct node* node,int key)
{
	if(node==NULL)
	return (newNode(key));
	
	if(key<node->key)
	node->left=insert(node->left,key);
	else if(key>node->key)
	node->right=insert(node->right,key);
	else 
	return node;
	
node->height=1+max(height(node->left),height(node->right));

int bal=balance(node);

if(bal>1 && key<node->left->key)
return rightRotate(node);

if(bal<-1 && key>node->right->key)
return leftRotate(node);

if(bal>1 && key>node->left->key)
{
	node->left=leftRotate(node->left);
	return rightRotate(node);
}

if(bal<-1 && key<node->right->key)
{
	node->right=rightRotate(node->right);
	return leftRotate(node);
}

return node;
}

void preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	struct node*root=NULL;
	
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,25);
	
	preorder(root);
	return 0;

}

