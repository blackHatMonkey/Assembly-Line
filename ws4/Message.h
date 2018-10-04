// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 04/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <fstream>
#include <string>

namespace w4 {
class Message {
       public:
        Message(std::ifstream& in, char c);
        auto empty() const -> bool { return sender.empty(); }
        auto display(std::ostream& out) const -> void;

       private:
        std::string sender;
        std::string replayTo;
        std::string message;
};

auto parseMessage(std::string& fullLine, std::string& sender,
                  std::string& receiver, std::string& message) -> void;
}  // namespace w4

#endif