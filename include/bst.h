// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <vector>
#include <string>
template <typename T>
class BST {
 private:
  struct Node {
    T data;
    int count;
    Node* left;
    Node* right;
  };
  Node* root;
  Node* addNode(Node* root, T data) {
    if (root == nullptr) {
      root = new Node;
      root->data = data;
      root->count = 1;
      root->left = nullptr;
      root->right = nullptr;
    } else if (root->data > data) {
      root->left = addNode(root->left, data);
    } else if (root->data < data) {
      root->right = addNode(root->right, data);
    } else {
      root->count++;
    }
    return root;
  }
  int searchTree(Node* root, T data) {
    if (!root) return 0;
    else if (data > root->data)
      return searchTree(root->right, data);
    else if (data < root->data)
      return searchTree(root->left, data);
    else return root->count;
  }
  int countHeight(Node* root) {
    if (root == nullptr) return 0;
    int a = countHeight(root->left);
    int b = countHeight(root->right);
    if (a > b)
      return a + 1;
    else return b + 1;
  }
  int countNodes(Node* root) {
    if (root == nullptr)
      return 0;
    else return countNodes(root->left) + countNodes(root->right) + 1;
  }
  void getTree(Node* root, std::vector<std::string>& arr) {
    if (root == nullptr) return;
    arr.push_back(root->data);
    getTree(root->left, arr);
    getTree(root->right, arr);
  }
  void deleteTree(Node* node) {
    if (node) {
      deleteTree(node->left);
      deleteTree(node->right);
      delete node;
    }
  }

 public:
  BST() : root(nullptr) {}
  ~BST() {
    deleteTree(root);
  }
  void add(const T& data) {
    root = addNode(root, data);
  }
  int search(T data) {
    return searchTree(root, data);
  }
  int depth() {
    return countHeight(root) - 1;
  }
  int count() {
    return countNodes(root);
  }
  std::string* get() {
    std::vector<std::string> v;
    getTree(root, v);
    std::string* tree = new std::string[v.size()];
    for (int i = 0; i < v.size(); ++i) {
      tree[i] = v[i];
    }
    return tree;
  }
};
#endif  // INCLUDE_BST_H_
