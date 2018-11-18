/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/11/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#include <cstddef>
#include <string>

#include "Utilities.h"

// comma is the default delimeter
char Utilities::m_delimiter = ',';

/**
 * @brief Set the field width for displaying.
 *
 * @param newWidth A width number.
 */
auto Utilities::setFieldWidth(size_t newWidth) -> void {
  m_widthField = newWidth;
}

/**
 * @brief Get the field width.
 *
 * @return size_t The current field width.
 */
auto Utilities::getFieldWidth() const -> size_t { return m_widthField; }

/**
 * @brief Set the delimeter for data retrival.
 *
 * @param delimiter A delimter.
 */
auto Utilities::setDelimiter(const char delimiter) -> void {
  m_delimiter = delimiter;
}

/**
 * @brief
 *
 * @return const char
 */
auto Utilities::getDelimiter() const -> const char { return m_delimiter; }

/**
 * @brief Extract one token from the line.
 *
 * @param str A line of text.
 * @param next_pos Current position in the line.
 * @param more True there are more tokens available and false otherwise.
 * @return const std::string The extracted token or empty string if not found.
 * @throws std::string when there is no dat between two delimeters.
 */
auto Utilities::extractToken(const std::string &str, size_t &next_pos,
                             bool &more) -> const std::string {
  auto nextDelimPos = str.find(m_delimiter, next_pos);
  auto token = str.substr(next_pos, nextDelimPos - next_pos);

  // throw an error if there is no data between two delimeters
  // example: test1,,test3,test4
  if (str[nextDelimPos + 1] == m_delimiter) {
    throw std::string("No data was found!");
  }

  // we need to keep track of the largest feild width for printing
  // only for the first token
  auto tokenSize = token.size();
  if (tokenSize > m_widthField) {
    m_widthField = tokenSize;
  }

  // account for delimeter in position for the next call
  next_pos = nextDelimPos + 1;

  // we have reached end of the line so no more tokens
  if (tokenSize == 0) {
    more = false;
  }

  return token;
}