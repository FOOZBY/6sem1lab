#include "tree_to_avl.h"
#include "tree_to_rbt.h"

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	Tree bst_tree;
	int N = 30000;

	cout << "N = " << N << endl;

	for (int i = 0; i < N; i++)
	{
		//tRee.insert(i);
		bst_tree.insert(rand() % 50000);
	}
	bst_tree.Find_depth();

	/////////////////////////////////////////////////


	Avl avl_tree;
	double avl_time = 0;
	chrono::duration<double, micro> duration;
	auto start = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	for (int j = 0; j < 100; j++)
	{
		avl_tree.clear();
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++)
		{
			avl_tree.insert(rand() % 5000000);
		}
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		avl_time += duration.count();
	}
	cout << "AVL depth: "; avl_tree.Find_depth();
	cout << "Время AVL: " << avl_time/100 << " mcs\n";
	/////////////////////////////////////////////////

	RBT rbt_tree;
	double rbt_time = 0;
	for (int j = 0; j < 100; j++)
	{
		rbt_tree.clear();
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < N; i++)
		{
			rbt_tree.insert(rand() % 5000000);
		}
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		rbt_time += duration.count();
	}
	cout << "RBT depth: "; rbt_tree.Find_depth();
	cout << "Время RBT: " << rbt_time / 100 << " mcs\n";
	system("pause");	
}