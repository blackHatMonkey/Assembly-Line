// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 8/9/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>
#include <vector>

namespace w1 {
class CString {
       public:
        void display(std::ostream &out) const;
        CString(char *new_str);

       private:
        const int MAX;
        std::vector<char> str;
};

std::ostream &operator<<(std::ostream &out, const CString &str);

}  // namespace w1

#endif