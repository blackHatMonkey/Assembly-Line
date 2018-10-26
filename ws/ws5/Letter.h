// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 07/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {
enum class Letter { Aplus, A, Bplus, B, Cplus, C, Dplus, D, F };

template <typename T>
const char* convertToString(T letter) {
        switch (letter) {
                case Letter::Aplus:
                        return "A+";
                case Letter::A:
                        return "A";
                case Letter::Bplus:
                        return "B+";
                case Letter::B:
                        return "B";
                case Letter::Cplus:
                        return "C+";
                case Letter::C:
                        return "C";
                case Letter::Dplus:
                        return "D+";
                case Letter::D:
                        return "D";
                default:
                        return "F";
        }
}

}  // namespace sict

#endif