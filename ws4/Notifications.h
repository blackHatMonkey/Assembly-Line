// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 04/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <array>
#include <iostream>
#include "Message.h"

namespace w4 {
class Notifications {
       public:
        Notifications() = default;
        Notifications(const Notifications& other);
        Notifications& operator=(const Notifications& other);
        Notifications(Notifications&& other);
        Notifications& operator=(Notifications&& other);
        auto operator+=(const Message& msg) -> void;
        auto display(std::ostream& os) const -> void;
        ~Notifications();

       private:
        std::array<Message*, 10> messages{nullptr};
        size_t fillIndex = 0;
};
}  // namespace w4

#endif