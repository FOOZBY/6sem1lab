#include "tree_to_avl.h"
//#include "tree_to_rbt.h"

int main()
{
	srand(time(NULL));

	Tree tRee;

	/*tRee.insert(7);
	tRee.insert(4);
	tRee.insert(6);
	tRee.insert(5);
	tRee.insert(3);
	tRee.insert(8);
	tRee.insert(10);
	tRee.insert(9);
	tRee.insert(11);*/

	for (int i = 0; i < 15; i++)
	{
		tRee.insert(i);
		//tRee.insert(rand() % 50);
	}

	tRee.Print_tree_as_tree();
	tRee.Find_depth();
	tRee.remove(0);
	tRee.Print_tree_as_tree();
	tRee.Find_depth();

	Avl tree;

	for (int i = 0; i < 15; i++)
	{
		tree.insert(i);
	}
	tree.Print_tree_as_tree();
	tree.Find_depth();
	tree.remove(7);
	tree.Print_tree_as_tree();
	system("pause");	
}