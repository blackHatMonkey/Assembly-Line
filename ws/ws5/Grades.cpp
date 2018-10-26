// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 07/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <string>

#include "Grades.h"

namespace sict {
Grades::Grades(const char* fileName) {
        std::ifstream file(fileName);
        if (file.is_open()) {
                auto studentNumber{0L};
                auto mark{0.0};

                while (file >> studentNumber >> mark) {
                        students.push_back(std::make_pair(studentNumber, mark));
                }

        } else {
                throw std::runtime_error("Failed to open file!");
        }
}
}  // namespace sict