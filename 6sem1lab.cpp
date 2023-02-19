#include "tree_to_avl.h"

int main()
{
	srand(time(NULL));

	Tree tRee;

	for (int i = 0; i < 15; i++)
	{
		tRee.insert(i);
	}

	tRee.Print_tree_as_tree();




	/*Avl tree;

	for (int i = 0; i < 15; i++)
	{
		tree.insert(i);
	}

	tree.Print_tree_as_tree();*/
	system("pause");	
}