// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 8/9/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "CString.h"
#include <iostream>
#include <vector>

// the number of characters that can be stored
int STORED = 3;

namespace w1 {
/*
 * Construct CString with a new C-style string.
 *
 * @param new_str A new C-style string.
 */
CString::CString(char *new_str) : MAX{STORED} {
        if (new_str) {
                for (auto i = 0; i < MAX && new_str[i]; i++) {
                        str.push_back(new_str[i]);
                }
        }
}

/*
 * Print out the contents of CString object.
 *
 * @param out An ostream object.
 * @param str A Cstring object.
 * @return ostream reference.
 *
 */
auto operator<<(std::ostream &out, const CString &str) -> std::ostream & {
        str.display(out);
        return out;
}

/*
 * Display the contents of the object.
 *
 * @param out ostream object.
 *
 */
auto CString::display(std::ostream &out) const -> void {
        for (auto &ch : str) {
                out << ch;
        }
}

}  // namespace w1