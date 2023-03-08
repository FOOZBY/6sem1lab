#include "tree_to_avl.h"
#include "tree_to_rbt.h"

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	Tree bst_tree;

	for (int i = 0; i < 15; i++)
	{
		//tRee.insert(i);
		bst_tree.insert(rand() % 50);
	}

	bst_tree.Print_tree_as_tree();
	bst_tree.Find_depth();


	/////////////////////////////////////////////////


	Avl avl_tree;

	for (int i = 0; i < 15; i++)
	{
		//tree.insert(i);
		avl_tree.insert(rand() % 50);
	}
	avl_tree.Print_tree_as_tree();
	avl_tree.Find_depth();

	/////////////////////////////////////////////////


	RBT rbt_tree;

	for (int i = 0; i < 15; i++)
	{
		//rbt_tree.insert(i);
		rbt_tree.insert(rand() % 50);
	}
	rbt_tree.Print_tree_as_tree();
	rbt_tree.Find_depth();

	system("pause");	
}