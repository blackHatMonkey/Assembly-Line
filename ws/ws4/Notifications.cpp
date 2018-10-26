// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 04/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>

#include "Message.h"
#include "Notifications.h"

namespace w4 {
/**
 * @brief Construct a new Notifications:: Notifications object
 *
 * @param other another Notifaction object.
 */
Notifications::Notifications(const Notifications& other) {
        for (auto i = 0u; i < messages.max_size(); i++) {
                messages[i] = new Message(*(other.messages[i]));
        }
        fillIndex = other.fillIndex;
}

/**
 * @brief Copy the content of another Notification object.
 *
 * @param other another Notification object.
 * @return Notifications& the current object.
 */
Notifications& Notifications::operator=(const Notifications& other) {
        if (this != &other) {
                for (auto i = 0u; i < messages.max_size(); i++) {
                        messages[i] = new Message(*(other.messages[i]));
                }
                fillIndex = other.fillIndex;
        }
        return *this;
}

/**
 * @brief Construct a new Notifications:: Notifications object
 *
 * @param other another Notification object.
 */
Notifications::Notifications(Notifications&& other) {
        for (auto i = 0u; i < messages.max_size(); i++) {
                messages[i] = other.messages[i];
                other.messages[i] = nullptr;
        }
        fillIndex = other.fillIndex;
}

/**
 * @brief Move the content of another Notification object.
 *
 * @param other another Notification object.
 * @return Notifications& current object.
 */
Notifications& Notifications::operator=(Notifications&& other) {
        if (this != &other) {
                for (auto i = 0u; i < messages.max_size(); i++) {
                        messages[i] = other.messages[i];
                        other.messages[i] = nullptr;
                }
                fillIndex = other.fillIndex;
        }
        return *this;
}

/**
 * @brief Add a new message to notifications.
 *
 * @param msg a new message to store.
 */
auto Notifications::operator+=(const Message& msg) -> void {
        if (fillIndex < messages.max_size()) {
                messages[fillIndex] = new Message(msg);
                fillIndex++;
        }
}

/**
 * @brief Display all notifications.
 *
 * @param os output object.
 */
auto Notifications::display(std::ostream& os) const -> void {
        for (auto i = 0u; i < fillIndex; i++) {
                messages[i]->display(os);
                os << std::endl;
        }
}

/**
 * @brief Destroy the Notifications:: Notifications object
 *
 */
Notifications::~Notifications() {
        for (auto& message : messages) {
                delete message;
        }
}
}  // namespace w4