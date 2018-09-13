// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 11/09/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <memory>
#include <string>

namespace w2 {
class Text {
       public:
        Text() = default;
        Text(const std::string& file_name);
        Text(const Text& other);
        Text& operator=(const Text& other);
        Text(Text&& other);
        Text& operator=(Text&& other) noexcept;
        size_t size() const { return capacity > 0 ? capacity + 1 : 0; };

       private:
        std::unique_ptr<std::string[]> collection;
        size_t capacity{0};
};

}  // namespace w2

#endif