#include "btree.h"
#include <iostream>
#include <iomanip>

int main()
{
  BTree *b1 = new BTree();
	b1->insert(8);
	b1->insert(5);
	b1->insert(2);
	b1->insert(12);
	b1->insert(9);
  b1->postorder(b1->findRoot());
  b1->destroy_tree();
}
