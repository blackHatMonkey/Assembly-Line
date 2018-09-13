// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 8/9/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "CString.h"

/*
 * Process a string and output the result.
 *
 * @param str C-style string.
 * @param out ostream reference for output.
 *
 */
auto process(char* str, std::ostream& out) -> void {
        static int count = 0;

        out << count << ": " << w1::CString(str) << std::endl;
        count++;
}
