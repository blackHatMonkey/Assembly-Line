// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 11/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <algorithm>
#include <fstream>
#include <istream>
#include <string>

#include "Text.h"

using namespace w2;

/*
 * Construct the object using a file name.
 *
 * @param file_name a string reference with the name of the file.
 *
 */

Text::Text(const std::string &file_name) {
  std::ifstream text_file(file_name);

  if (text_file.is_open()) {
    // need to add one since the last new line is not read
    capacity = std::count(std::istreambuf_iterator<char>(text_file),
                          std::istreambuf_iterator<char>(), '\n') +
               1;

    // need to reset the position
    text_file.seekg(0);

    collection = new std::string[capacity];

    auto line = std::string();
    for (auto i = 0u; i < capacity; i++) {
      std::getline(text_file, line);
      collection[i] = line;
    }
  }
}

/*
 * Copy the other object in to the current object.
 *
 * @param other another Text object.
 * @return a reference to the current object.
 *
 */
Text &Text::operator=(const Text &other) {
  if (this != &other) {
    delete[] collection;
    this->capacity = other.capacity;
    this->collection = new std::string[capacity];

    for (auto i = 0lu; i < capacity; i++) {
      collection[i] = other.collection[i];
    }
  }
  return *this;
}

/*
 * Copy the other object in to the current object.
 *
 * @param other another Text object.
 *
 */
Text::Text(const Text &other) {
  this->capacity = other.capacity;
  this->collection = new std::string[capacity];

  for (auto i = 0lu; i < capacity; i++) {
    collection[i] = other.collection[i];
  }
}

/*
 * Move the other object into the current object.
 *
 * @param other an rvalue of Text object.
 * @return reference to the current object.
 *
 */
Text &Text::operator=(Text &&other) noexcept {
  if (this != &other) {
    delete[] collection;
    capacity = other.capacity;
    collection = other.collection;
    other.collection = nullptr;
  }
  return *this;
}

/*
 * Move the other object into the current object.
 *
 * @param other an rvalue of Text object.
 *
 */
Text::Text(Text &&other) {
  this->capacity = other.capacity;
  this->collection = other.collection;
  other.collection = nullptr;
}