#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <iostream>
#include <string>
#include <cstdlib> // For std::stoi
#include <cctype>  // For std::isdigit
#include <algorithm>

class TAArray {
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea* ta);
    bool add(TextArea* ta, int index);
    TextArea* get(const std::string& index) const;
    TextArea* get(int index) const;
    TextArea* remove(const std::string& index);
    TextArea* remove(int index);
    void print();
    inline int getSize() { return size; }

  private:
    TextArea** elements;
    int size;
    int capacity;
    void resize();
    bool isNumber(const std::string& str) const;
};
#endif