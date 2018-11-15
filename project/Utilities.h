/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/11/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstddef>
#include <string>

class Utilities {
public:
  auto setFieldWidth(size_t) -> void;
  auto getFieldWidth() const -> size_t;
  auto extractToken(const std::string &str, size_t &next_pos, bool &more)
      -> const std::string;
  static auto setDelimiter(const char) -> void;
  auto getDelimiter() const -> const char;

private:
  size_t m_widthField = 1;
  static char m_delimiter;
};

#endif