/*
 * Name: Brian Smith
 * Seneca Student ID: 137105177
 * Seneca email: bsmith55@myseneca.ca
 * Date of completion: 12/11/2018
 *
 * I confirm that I am the only author of this file
 * and the content was created entirely by me.
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder(std::string &line) {
  Utilities util;
  auto more = true;
  auto pos = (size_t)0;

  m_name = util.extractToken(line, pos, more);

  if (more) {
    m_product = util.extractToken(line, pos, more);
  }

  std::vector<std::string> items;

  // TODO finish this
  while (more) {
    items.push_back(util.extractToken(line, pos, more));
  }

  m_widthField = util.getFieldWidth();

  m_cntItem = items.size();
  m_lstItem = new ItemInfo *[m_cntItem];

  for (auto i = 0u; i < m_cntItem; i++) {
    m_lstItem[i] = new ItemInfo(items[i]);
  }
}

CustomerOrder::CustomerOrder(CustomerOrder &&other) noexcept {
  m_lstItem = other.m_lstItem;
  m_cntItem = other.m_cntItem;
  m_name = other.m_name;
  m_product = other.m_product;

  other.m_cntItem = 0;
  other.m_lstItem = nullptr;
}

CustomerOrder &CustomerOrder::operator=(CustomerOrder &&other) {
  if (this != &other) {
    for (auto i = 0u; i < m_cntItem; i++) {
      delete m_lstItem[i];
    }
    delete[] m_lstItem;

    m_lstItem = other.m_lstItem;
    m_cntItem = other.m_cntItem;
    m_name = other.m_name;
    m_product = other.m_product;

    other.m_cntItem = 0;
    other.m_lstItem = nullptr;
  }

  return *this;
}

CustomerOrder::~CustomerOrder() {
  for (auto i = 0u; i < m_cntItem; i++) {
    delete m_lstItem[i];
  }
  delete[] m_lstItem;
}

auto CustomerOrder::getItemFillState(std::string itemName) const -> bool {
  for (auto i = 0u; i < m_cntItem; i++) {
    if (m_lstItem[i]->m_itemName == itemName) {
      return m_lstItem[i]->m_fillState;
    }
  }

  return true;
}

auto CustomerOrder::getOrderFillState() const -> bool {
  for (auto i = 0u; i < m_cntItem; i++) {
    if (!m_lstItem[i]->m_fillState) {
      return false;
    }
  }

  return true;
}

auto CustomerOrder::fillItem(Item &item, std::ostream &out) -> void {
  for (auto i = 0u; i < m_cntItem; i++) {
    if (item.getName() == m_lstItem[i]->m_itemName) {
      if (item.getQuantity() > 0) {
        item.updateQuantity();
        m_lstItem[i]->m_fillState = true;
        m_lstItem[i]->m_serialNumber = item.getSerialNumber();

        out << "Filled ";
      } else {
        out << "Unable to fill ";
      }
      out << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName
          << "]" << std::endl;
    }
  }
}

auto CustomerOrder::display(std::ostream &out) const -> void {
  out << m_name << " - " << m_product << std::endl;

  for (auto i = 0u; i < m_cntItem; i++) {
    out << "[" << std::setw(6) << std::setfill('0')
        << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
        << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";

    if (m_lstItem[i]->m_fillState) {
      out << "FILLED";
    } else {
      out << "MISSING";
    }

    out << std::endl;
  }
}