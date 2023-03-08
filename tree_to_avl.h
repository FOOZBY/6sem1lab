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

	Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	Node* rem_elem(Node* p,int data)
	{
		if (!p) return 0;
		if (data < p->data)
			p->left = rem_elem(p->left, data);
		else if (data > p->data)
			p->right = rem_elem(p->right, data);
		else //  data == p->data 
		{
			Node* q = p->left;
			Node* r = p->right;
			delete p;
			if (!r) return q;
			Node* min = min_elem_ret(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}

public:
	void insert(int data)
	{
		add_new_elem(this->root, data);
	}
	void remove(int data)
	{
		if (data == this->root->data)
		{
			this->root = rem_elem(root, data);
		}
		else
		{
			rem_elem(root, data);
		}
	}
};