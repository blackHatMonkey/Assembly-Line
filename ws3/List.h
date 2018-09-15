// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 15/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

#include <cstddef>

template <typename T, size_t N>
class List {
       public:
        List() = default;
        size_t size() const { return capacity; }
        const T& operator[](int index) const { return collection[index]; }
        void operator+=(const T& element) {
                if (capacity < N - 1) {
                        collection[capacity] = element;
                        capacity++;
                }
        }

       private:
        T collection[N]{};
        size_t capacity{0};
};

#endif