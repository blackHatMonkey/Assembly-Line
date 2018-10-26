// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 04/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <string>

#include "Message.h"

using std::string;

namespace w4 {
/**
 * @brief Construct a new Message:: Message object
 *
 * @param in a file stream object.
 * @param c a delimeter for the line.
 */
Message::Message(std::ifstream& in, char c) {
        if (in.is_open()) {
                string line;
                std::getline(in, line, c);

                parseMessage(line, sender, replayTo, message);

                if (sender.empty() || message.empty()) {
                        sender.clear();
                        replayTo.clear();
                        message.clear();
                }
        }
}

/**
 * @brief Display all messages.
 *
 * @param out an output object.
 */
auto Message::display(std::ostream& out) const -> void {
        out << "Message" << std::endl;
        out << " User  : " << sender << std::endl;

        if (!replayTo.empty()) {
                out << " Reply : " << replayTo << std::endl;
        }

        out << " Tweet : " << message << std::endl;
}

/**
 * @brief Parse the contents of the message.
 *
 * The input comes in three different formats:
 *      1. sender @receiver message
 *      2. sender message
 *      3. sender
 * Case 1 and 2 are valid while case 3 is invalid and should be discarded.
 *
 * @param fullLine a string content to parse.
 * @param sender sender of the message.
 * @param receiver receiver of the message.
 * @param message the message in tweet.
 */
auto parseMessage(string& fullLine, string& sender, string& receiver,
                  string& message) -> void {
        auto spaceIndex = fullLine.find(' ');

        if (spaceIndex != string::npos) {
                sender = fullLine.substr(0, spaceIndex);
                fullLine.erase(0, spaceIndex + 1);

                if (fullLine[0] == '@') {
                        spaceIndex = fullLine.find(' ');
                        receiver = fullLine.substr(1, spaceIndex - 1);
                        fullLine.erase(0, spaceIndex + 1);
                }

                message = fullLine;
        }
}
}  // namespace w4