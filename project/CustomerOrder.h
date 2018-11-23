/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/11/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>

#include "Item.h"

struct ItemInfo {
  std::string m_itemName;
  size_t m_serialNumber = 0;
  bool m_fillState = false;

  ItemInfo(std::string src) : m_itemName(src){};
};

class CustomerOrder {
public:
  CustomerOrder() = default;
  CustomerOrder(std::string &line);
  CustomerOrder(const CustomerOrder &);
  CustomerOrder &operator=(const CustomerOrder &) = delete;
  CustomerOrder(CustomerOrder &&) noexcept;
  CustomerOrder &operator=(CustomerOrder &&);
  ~CustomerOrder();
  auto getItemFillState(std::string) const noexcept -> bool;
  auto getOrderFillState() const -> bool;
  auto fillItem(Item &item, std::ostream &) -> void;
  auto display(std::ostream &) const -> void;

private:
  std::string m_name;
  std::string m_product;
  size_t m_cntItem = 0;
  ItemInfo **m_lstItem = nullptr;
  static size_t m_widthField;
};

#endif