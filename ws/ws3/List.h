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
#include <stdexcept>

template <typename T, size_t N>
class List {
       public:
        List() = default;
        size_t size() const { return capacity; }
        const T& operator[](int index) const;
        void operator+=(const T& element);

       private:
        T collection[N];
        size_t capacity{0};
};

template <typename T, size_t N>
void List<T, N>::operator+=(const T& element) {
        if (capacity < N - 1) {
                collection[capacity] = element;
                capacity++;
        }
}

template <typename T, size_t N>
const T& List<T, N>::operator[](int index) const {
        if (index < 0 || static_cast<size_t>(index) > capacity) {
                throw std::out_of_range("Index is out of range");
        } else {
                return collection[index];
        }
}
#endif