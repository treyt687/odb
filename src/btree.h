#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

using namespace std;

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

  int getHeight(Node* p);
  void postorder(Node* p);
  void printRow(const Node *p, const int height, int depth);
  void getLine(const Node *root, int depth, vector<int>& vals);
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
