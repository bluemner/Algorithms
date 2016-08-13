#include <stdio.h>
#include <limits.h>
struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
};
struct Node* makeNode(int key_value)
{
	struct Node* leaf = (struct *Node) malloc((struct *Node));
			leaf->left = 0;
			leaf->right = 0;
			leaf->key = key_value;
}
void insert_key(int key_value, struct Node* node)
{
	if(node == 0)
	{
		return;
	}
	if(node->key <= key_value)
	{
		//insert node
		if(node->left ==0)
		{
			node->left = makeNode(key_value);		
		}else
		{
			insert_key(key_value, node->left);
		}
		
	}else if(node->key > key_value)
	{
		//insert node
		if(node->right ==0)
		{
			node->right = makeNode(key_value);		
		}else
		{
			insert_key(key_value, node->right);
		}
		
	}
}
void insert_node(struct Node* node, struct Node* tree)
{
	if(node == 0 || tree == 0)
	{
		return;
	}
	if(tree->key <= key_value)
	{
		//insert node
		if(tree->left ==0)
		{
			tree->left = node;		
		}else
		{
			insert_key(key_value, tree->left);
		}
		
	}else if(tree->key > key_value)
	{
		//insert node
		if(tree->right ==0)
		{
			tree->right = node;		
		}else
		{
			insert_key(key_value, tree->right);
		}
		
	}
}

int main()
{
	return 0;
}
