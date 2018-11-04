#ifndef ITEM_H

#include <string>

class Item {
 public:
  static int m_widthField;
  Item(const std::string &line);
  auto getName() const -> const std::string &;
  auto getSerialNumber() -> const unsigned int;
  auto getQuantity() -> const unsigned int;
  auto updateQuantity() -> void;
  auto display(std::ostream &os, bool full) const -> void;

 private:
  std::string m_name;
  std::string m_description;
  unsigned int m_serialNumber = 0;
  unsigned int m_quantity = 0;
};

#endif