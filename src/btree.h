#ifndef BTREE_H
#define BTREE_H

#include <iostream>

typedef int DataElement;

struct Node {
  DataElement key_value;
  Node *left, *right;

  Node();
};

class BTree {

public:
  BTree();
  ~BTree();

  void printTree(Node* node);
  void insert(DataElement key);
  Node *search(DataElement key);
  void destroy_tree();
  Node *findRoot();

private:
  void insert(DataElement key, Node *leaf);
  void destroy_tree(Node *leaf);
  Node *search(DataElement key, Node *leaf);

  Node *root;
};

#endif
