#include "Header.h"

class Avl : public Tree
{
	int height(Node* p)
	{
		return p ? p->height : 0;
	}

	int bfactor(Node* p)
	{
		return height(p->right) - height(p->left);
	}

	void fixheight(Node* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	Node* rotateright(Node* p) // правый поворот вокруг p
	{
		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
		Node* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	void add_new_elem(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
		}
		else
		{
			if (data < node->data)
			{
				add_new_elem(node->left, data);
			}
			else if (data > node->data)
			{
				add_new_elem(node->right, data);
			}
			//если data == node->data, то такой ключ уже есть в дереве, поэтому мы ничего не делаем
			node = balance(node);
		}
	}

public:
	void insert(int data)
	{
		add_new_elem(root, data);
	}
};