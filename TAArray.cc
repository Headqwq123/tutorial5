#include "TAArray.h"

TAArray::TAArray() {
    size = 0;
    capacity = 10;
    elements = new TextArea*[capacity];
}

TAArray::~TAArray() {
    for (int i = 0; i < size; ++i) {
        delete elements[i];
    }
    delete[] elements;
}

bool TAArray::add(TextArea* ta) {
    if (size >= capacity) {
        resize();
    }
    elements[size++] = ta;
    return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (index < 0 || index > size) {
        return false;
    }
    if (size >= capacity) {
        resize();
    }
    for (int i = size; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = ta;
    ++size;
    return true;
}

bool TAArray::isNumber(const std::string& str) const {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return elements[i];
        }
    }
    std::cerr << "Error: TextArea with ID '" << id << "' not found." << std::endl;
    return nullptr;
}
 
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return elements[index];
}

TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (elements[i]->getId() == id) {
            return remove(i);
        }
    }
    std::cerr << "Error: TextArea with ID '" << id << "' not found." << std::endl;
    return nullptr;
}
    

TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    TextArea* removed = elements[index];
    for (int i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --size;
    return removed;
}

void TAArray::print() {
    for (int i = 0; i < size; ++i) {
        elements[i]->print();
    }
}

void TAArray::resize() {
    capacity *= 2;
    TextArea** newElements = new TextArea*[capacity];
    for (int i = 0; i < size; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}
