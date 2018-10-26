// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 07/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include "Letter.h"

namespace sict {

class Grades {
       public:
        Grades(const char* fileName);
        Grades(const Grades&) = delete;
        Grades& operator=(const Grades&) = delete;
        Grades(Grades&&) = delete;
        Grades& operator=(Grades&&) = delete;
        template <typename F>
        void displayGrades(std::ostream& out, F& lambda) const {
                for (auto& s : students) {
                        out << std::right << std::setw(10) << s.first << " "
                            << std::setw(5) << std::setprecision(2)
                            << std::fixed << s.second << std::left << " "
                            << std::setw(4) << convertToString(lambda(s.second))
                            << std::endl;
                }
        }

       private:
        std::vector<std::pair<int, double>> students;
};
}  // namespace sict

#endif