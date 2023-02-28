#include <iostream>
#include <time.h>
using namespace std;

class Tree
{
public:
	struct Node
	{
		Node* left, * right;
		int data;
		int height;
		Node(int data, Node* left = nullptr, Node* right = nullptr, int height = 1)
		{
			this->data = data;
			this->left = left;
			this->right = right;
			this->height = height;
		}
	};
	Node* root;
	Node* min_elem_ret(Node*& node)
	{
		if (node->left != nullptr)
		{
			min_elem_ret(node->left);
		}
		else
		{
			return node;
		}
	}
private:


	void print_tree_as_tree(Node* node, int lvl);
	void inorder(Node* node);
	
	void add_new_elem(Node*& node, int data);
	Node* search_elem(Node*& node, int data)
	{
		if (node == nullptr || node->data == data)
		{
			return node;
		}
		if (data < node->data)
		{
			search_elem(node->left, data);
		}
		else
		{
			search_elem(node->right, data);
		}
	}
	void del_all(Node*& current);
	int find_depth(Node* tree);
	Node* rem_elem(Node* p, int data)
	{
		if (p == nullptr)
			return nullptr;
		if (data < p->data)
			p->left = rem_elem(p->left, data);
		else if (data > p->data)
			p->right = rem_elem(p->right, data);
		else //  data == p->data 
		{
			if (p->left && p->right)
			{
				p->data = min_elem_ret(p->right)->data;
				p->right = rem_elem(p->right, p->data);
			}
			else
			{
				if (p->left != nullptr)
					p = p->left;
				else if (p->right != nullptr)
					p = p->right;
				else
					p = nullptr;
			}
		}
		return p;
	}
	
public:
	Tree();
	~Tree();

	void insert(int data)
	{
		add_new_elem(root, data);
	}

	Node* search(int data)
	{
		return search_elem(root, data);
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

	void Inorder()
	{
		cout << "Infix: ";
		inorder(root);
		cout << endl;
	}

	void Print_tree_as_tree()
	{
		cout << endl;
		print_tree_as_tree(root, 0);
	}

	void Find_depth()
	{
		cout << "Depth = " << find_depth(root) << endl;
	}
};

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	this->del_all(this->root);
	this->root = nullptr;
}

inline int Tree::find_depth(Node* tree)
{
	int ret = 0;
	if (tree)
	{
		int lDepth = find_depth(tree->left);
		int rDepth = find_depth(tree->right);
		ret = max(lDepth + 1, rDepth + 1);
	}
	return ret;
}

inline void Tree::add_new_elem(Node*& node, int data)
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
	}
}

inline void Tree::del_all(Node*& current)
{
	if (current != nullptr)
	{
		del_all(current->left);
		del_all(current->right);
		delete current;
	}
}

inline void Tree::inorder(Node* node)
{
	if (node != nullptr)
	{
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}

inline void Tree::print_tree_as_tree(Node* node, int lvl)
{
	if (node != nullptr)
	{
		print_tree_as_tree(node->right, lvl + 1);
		for (int i = 0; i < lvl; i++)
			cout << "\t";
		cout << "........" << node->data << endl;
		print_tree_as_tree(node->left, lvl + 1);
	}
}

class MyClass : public Tree
{
public:


private:

};