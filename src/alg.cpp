// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
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
