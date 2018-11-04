#include <cstddef>
#include <string>

#include "Utilities.h"

auto Utilities::setFieldWidth(size_t newWidth) -> void {
  m_widthField = newWidth;
}

auto Utilities::getFieldWidth() const -> size_t { return m_widthField; }

auto Utilities::setDelimiter(const char delimiter) -> void {
  m_delimiter = delimiter;
}
auto Utilities::getDelimiter() const -> const char { return m_delimiter; }

auto Utilities::extractToken(const std::string &str, size_t &next_pos,
                             bool &more) -> const std::string {
  auto nextDelimPos = str.find(m_delimiter, next_pos);
  auto token = str.substr(next_pos, nextDelimPos);
  auto tokenSize = token.size();

  if (tokenSize > 0) {
    if (tokenSize > m_widthField) {
      m_widthField = tokenSize;
    }

    next_pos = nextDelimPos;
    more = true;
    return token;
  } else {
    more = false;
    throw std::string("No data was found!");
  }
}