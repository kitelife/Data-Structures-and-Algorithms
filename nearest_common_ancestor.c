#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

int getPath(Node* root, Node* target, int* path, int deep)
{
	deep ++;
	if(root->data != target->data)
	{
		int left_result = 0, right_result = 0;
		if(root->left != NULL)
		{
			left_result = getPath(root->left, target, path, deep);
		}
		if(root->right != NULL)
		{
			right_result = getPath(root->right, target, path, deep);
		}

		if(left_result || right_result)
		{
			path[deep] = root->data;
			return 1;
		}
		else
			return 0;
	}
	else
	{
		path[deep] = root->data;
		return 1;
	}
}

int find_nca(Node* root, int tree_deep, Node* x, Node* y)
{
	int nca;
	int* path_to_x = (int*)malloc(tree_deep*4);
	int* path_to_y = (int*)malloc(tree_deep*4);
	getPath(root, x, path_to_x, -1);
	getPath(root, y, path_to_y, -1);
	int pos = 0;
	while(pos < tree_deep)
	{
		if(path_to_x[pos] != path_to_y[pos])
		{
			nca = path_to_x[pos-1];
			break;
		}
		else
			pos++;
	}
	free(path_to_x);
	free(path_to_y);

	return nca;
}

int main()
{
	Node* a = (Node*)malloc(sizeof(Node));
	Node* b = (Node*)malloc(sizeof(Node));
	Node* c = (Node*)malloc(sizeof(Node));
	Node* d = (Node*)malloc(sizeof(Node));
	Node* e = (Node*)malloc(sizeof(Node));
	Node* f = (Node*)malloc(sizeof(Node));
	a->data = 1;
	b->data = 2;
	c->data = 3;
	d->data = 4;
	e->data = 5;
	f->data = 6;
	a->left = b;
	a->right = NULL;
	b->left = c;
	b->right = d;
	c->left = e;
	c->right = f;
	e->left = NULL;
	e->right = NULL;
	f->left = NULL;
	f->right = NULL;
	// print out the nearest common ancestor num
	printf("%d\n", find_nca(a, 4, a, e));

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);

	return 0;
}
