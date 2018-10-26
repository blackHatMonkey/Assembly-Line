// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <stdexcept>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
        std::cout << "Command Line: ";
        for (int i = 0; i < argc; i++) std::cout << argv[i] << ' ';
        std::cout << std::endl;

        if (argc == 1) {
                std::cerr << "\n*** Insufficient number of arguments ***\n";
                std::cerr << "Usage: " << argv[0] << " fileName \n";
                return 1;
        } else if (argc != 2) {
                std::cerr << "\n*** Too many arguments ***\n";
                std::cerr << "Usage: " << argv[0] << " fileName \n";
                return 2;
        }

        auto letter = [](double mark) -> sict::Letter {
                if (mark >= 90) {
                        return Letter::Aplus;
                } else if (mark >= 80) {
                        return Letter::A;
                } else if (mark >= 75) {
                        return Letter::Bplus;
                } else if (mark >= 70) {
                        return Letter::B;
                } else if (mark >= 65) {
                        return Letter::Cplus;
                } else if (mark >= 60) {
                        return Letter::C;
                } else if (mark >= 55) {
                        return Letter::Dplus;
                } else if (mark >= 50) {
                        return Letter::D;
                } else {
                        return Letter::F;
                }
        };

        try {
                Grades grades(argv[1]);
                grades.displayGrades(std::cout, letter);
        } catch (std::runtime_error& error) {
                std::cout << "There was a problem opening the file!"
                          << std::endl;
                return 1;
        }

        return 0;
}