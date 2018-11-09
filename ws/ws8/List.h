// Workshop 8 - Smart Pointers
// List.h
#ifndef W8_LIST_H
#define W8_LIST_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace w8 {
template <typename T> class List {
  std::vector<T> list;

public:
  List() {}
  List(const char *fn) {
    std::ifstream file(fn);
    if (!file)
      throw std::string("*** Failed to open file ") + std::string(fn) +
          std::string(" ***");
    while (file) {
      T e;
      if (e.load(file))
        list.push_back(*new T(e));
    }
  }
  size_t size() const { return list.size(); }
  const T &operator[](size_t i) const { return list[i]; }

  List<T> &operator+=(const std::unique_ptr<T> &newItem) {
    list.push_back(*newItem);
    return *this;
  }

  List<T> &operator+=(const T *newItem) {
    list.push_back(*newItem);
    return *this;
  }

  void display(std::ostream &os) const {
    os << std::fixed << std::setprecision(2);
    for (auto &e : list)
      e.display(os);
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &l) {
  l.display(os);
  return os;
}
} // namespace w8
#endif