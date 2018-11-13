/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/11/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#ifndef ITEM_H

#include <string>

class Item {
public:
  static size_t m_widthField;
  Item(const std::string &line);
  auto getName() const -> const std::string &;
  auto getSerialNumber() -> const size_t;
  auto getQuantity() -> const size_t;
  auto updateQuantity() -> void;
  auto display(std::ostream &os, bool full) const -> void;

private:
  std::string m_name;
  std::string m_description;
  size_t m_serialNumber = 0;
  size_t m_quantity = 0;
};

#endif