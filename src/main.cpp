#include "btree.h"
#include <iostream>

int main()
{
    auto b1 = new BTree();
    for (auto i = 0; i < 5; i++)
        b1->insert(i);
    auto x = b1->search(3)->right->key_value;
    std::cout << x << std::endl;
    b1->printTree(b1->findRoot());
    b1->destroy_tree();
}