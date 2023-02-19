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
private:


	void print_tree_as_tree(Node* node, int lvl);
	void inorder(Node* node);
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

	void remove(int data);

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
		cout << find_depth(root) << endl;
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

inline void Tree::remove(int data)
{
	Node* node = root;
	Node* parent = nullptr;
	while (node && node->data != data)
	{
		parent = node;
		if (data < node->data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	if (node == nullptr)
	{
		cout << "такого элемента нет в дереве" << endl;
		return;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		if (parent->left == node)
			parent->left = nullptr;
		if (parent->right == node)
			parent->right = nullptr;
		delete node;
		return;
	}
	if (node->left == nullptr)
	{
		if (parent->left == node)
			parent->left = node->right;
		if (parent->right == node)
			parent->right = node->right;
		delete node;
		return;
	}
	if (node->right == nullptr)
	{
		if (parent->left == node)
			parent->left = node->left;
		if (parent->right == node)
			parent->right = node->left;
		delete node;
		return;
	}
	if (node->left && node->right)
	{
		Node* temp = nullptr;
		temp = min_elem_ret(node->right);
		remove(temp->data);
		if (parent->left == node)
		{
			parent->left = temp;
			temp->left = node->left;
			temp->right = node->right;
		}
		if (parent->right == node)
		{
			parent->right = temp;
			temp->left = node->left;
			temp->right = node->right;
		}
		delete node;
		return;
	}
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
		cout << ".........." << node->data << endl;
		print_tree_as_tree(node->left, lvl + 1);
	}
}

class MyClass : public Tree
{
public:


private:

};