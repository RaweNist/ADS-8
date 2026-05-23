// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return;
  }
  while (!file.eof()) {
    std::string word = "";
    char ch = file.get();
    while (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
      if ('A' <= ch && ch <= 'Z')
        ch += 'a' - 'A';
      word += ch;
      ch = file.get();
    }
    if (word != "")
      tree.add(word);
  }
  file.close();
}
void printFreq(BST<std::string>& tree) {
  int size = tree.count();
  std::string* words = tree.get();
  int* count = new int[size];
  std::ofstream file("result.txt");
  if (!file) {
    std::cout << "File error!" << std::endl;
    return;
  }
  for (int i = 0; i < size; ++i) {
    count[i] = tree.search(words[i]);
  }
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i+1; j < size; ++j) {
      int x = count[i];
      int y = count[j];
      std::string xstr = words[i];
      std::string ystr = words[j];
      if (x < y) {
        words[i] = ystr;
        words[j] = xstr;
        count[i] = y;
        count[j] = x;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    file << words[i] << " " << count[i] << std::endl;
  }
  file.close();
}
