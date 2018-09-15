// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 15/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {
       public:
        Pair() = default;
        Pair(const A& element_a, const B& element_b)
            : a{element_a}, b{element_b} {}
        const A& getKey() const { return a; }
        const B& getValue() const { return b; }

       private:
        A a;
        B b;
};

#endif