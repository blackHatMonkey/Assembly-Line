// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 11/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>

#include "Text.h"

using namespace std::string_literals;
using namespace w2;

Text::Text(const std::string& file_name) {
        std::ifstream text_file(file_name);

        if (text_file.is_open()) {
                auto line{""s};

                // count the lines first to reduce allocation time
                while (std::getline(text_file, line)) {
                        capacity++;
                }

                collection = new std::string[capacity];

                // need to reset the position and clear error to read again
                text_file.clear();
                text_file.seekg(0, text_file.beg);

                for (auto i = 0; std::getline(text_file, line); i++) {
                        collection[i] = line;
                }
        }
}

Text& Text::operator=(const Text& other) {
        if (this != &other) {
                delete [] collection;
                this->capacity = other.capacity;
                this->collection = new std::string[capacity];

                for (auto i = 0lu;i< capacity; i++) {
                        collection[i] = other.collection[i];
                }
        }
        return *this;
}

Text::Text(const Text& other) {
        this->capacity = other.capacity;
        this->collection = new std::string[capacity];
        
        for (auto i = 0lu;i< capacity; i++) {
                collection[i] = other.collection[i];
        }
}

Text& Text::operator=(Text&& other) noexcept {
        if (this != &other) {
                delete [] collection;
                capacity = other.capacity;
                collection = other.collection;
                other.capacity = 0u;
                other.collection = nullptr;
        }
        return *this;
}

Text::Text(Text&& other) {
        this->capacity = other.capacity;
        this->collection = other.collection;
        other.capacity = 0;
        other.collection = nullptr;

}