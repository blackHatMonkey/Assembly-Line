#ifndef UTILITIES_H

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
  size_t m_widthField = 0;
  static char m_delimiter;
};

#endif