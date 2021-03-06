#include <iostream>
#include <string>
#include <iomanip>
#include "btree.h"
#include <algorithm>

using namespace std;

Node::Node()
{
    key_value = 0;
    left = NULL;
    right = NULL;
}

BTree::BTree()
{
  root=NULL;
}

BTree::~BTree()
{
  destroy_tree();


}

int BTree::getHeight(Node* p) {
  if (p == NULL)
  {
     return -1;
  }

  int left = getHeight(p->left);
  int right = getHeight(p->right);

  return 1 + std::max(left, right);
}

void BTree::postorder(Node* p)
{
    int height = getHeight(p) * 2;
    for (int i = 0 ; i < height; i ++) {
       printRow(p, height, i);
    }
}

void BTree::printRow(const Node *p, const int height, int depth) {
  vector<int> vec;
  getLine(p, depth, vec);
  cout << setw((height - depth)*2); // scale setw with depth
  bool toggle = true; // start with left
    if (vec.size() > 1) {
      for (int v : vec) {
        if (v != (1<<31)) {
          if (toggle)
            cout << "/" << "   ";
          else
            cout << "\\" << "   ";
        }
        toggle = !toggle;
      }
      cout << endl;
      cout << setw((height - depth)*2);
    }
    for (int v : vec) {
      if (v != (1<<31))
          cout << v << "   ";
    }
    cout << endl;
}
void BTree::getLine(const Node *root, int depth, vector<int>& vals) {
  if (depth <= 0 && root != nullptr) {
                vals.push_back(root->key_value);
                return;
        }
        if (root->left != nullptr)
                getLine(root->left, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back((1<<31));
        if (root->right != nullptr)
                getLine(root->right, depth-1, vals);
        else if (depth-1 <= 0)
                vals.push_back((1<<31));
}

void BTree::destroy_tree(Node *leaf)
{
  if (leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BTree::insert(DataElement key, Node *leaf)
{
  if (key < leaf->key_value)
  {
    if (leaf->left!=NULL)
    {
      insert(key, leaf->left);
    }
    else
    {
      leaf->left = new Node;
      leaf->left->key_value=key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  }
  else if (key >= leaf->key_value)
  {
    if (leaf->right != NULL)
    {
      insert(key, leaf->right);
    }
    else
    {
      leaf->right = new Node;
      leaf->right->key_value = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

Node *BTree::search(DataElement key, Node *leaf)
{
  if (leaf!=NULL)
  {
    if (key==leaf->key_value)
      return leaf;
    else if (key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

Node *BTree::search(DataElement key)
{
  return search(key, root);
}

void BTree::insert(DataElement key)
{
  if (root!=NULL)
    insert(key, root);
  else
  {
    root = new Node;
    root->key_value = key;
    root->left = NULL;
    root->right = NULL;
  }
}

Node *BTree::findRoot()
{
    return root;
}

void BTree::destroy_tree()
{
  destroy_tree(root);
}
