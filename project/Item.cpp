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

#include "Item.h"
#include "Utilities.h"

// start off with at least one space
size_t Item::m_widthField = 1;

Item::Item(const std::string &line) {
  Utilities util;
  auto more = true;
  auto pos = (size_t)0;

  m_name = util.extractToken(line, pos, more);

  if (more) {
    // need to convert it to an int to match serial's type
    m_serialNumber = std::stoi(util.extractToken(line, pos, more));
  } else {
    std::cerr << "Failed to get second token!" << std::endl;
    more = false;
  }

  if (more) {
    // need to convert it to an int to match quantity's type
    m_quantity = std::stoi(util.extractToken(line, pos, more));
  } else {
    std::cerr << "Failed to get third token!" << std::endl;
    more = false;
  }

  if (more) {
    m_description = util.extractToken(line, pos, more);
  } else {
    std::cerr << "Failed to get fourth token!" << std::endl;
  }

  // we need it for display to work properly
  m_widthField = util.getFieldWidth();
}

/**
 * @brief Return the name of the product.
 *
 * @return const std::string& Name of the product.
 */
auto Item::getName() const -> const std::string & { return m_name; }

/**
 * @brief Return the serial number of product.
 *
 * @return const size_t Serial number of the product.
 */
auto Item::getSerialNumber() -> const size_t { return m_serialNumber; }

/**
 * @brief Return the remaining quantity of the product.
 *
 * @return const size_t Remaining quantity of product.
 */
auto Item::getQuantity() -> const size_t { return m_quantity; }

/**
 * @brief Reduce the quantity of one.
 *
 */
auto Item::updateQuantity() -> void {
  if (m_quantity > 0) {
    m_quantity--;
  }
}

/**
 * @brief Display the product in two format:
 * Full:
 * <----m_width----><---6--->         <----m_width---->
 * productName      [xxxxxx] Quantity: x               Description: ...
 *
 * Compact:
 * <----m_width----><---6--->
 * productName      [xxxxxx]
 *
 * Both version insert a new line at the end.
 *
 * @param os Output object.
 * @param full Wether it should display the full or compact format.
 */
auto Item::display(std::ostream &os, bool full) const -> void {
  auto serialWidth = 6;

  if (full) {
    os << std::left << std::setw(m_widthField) << m_name << '['
       << std::setw(serialWidth) << std::setfill('0') << std::right
       << m_serialNumber << std::left << std::setfill(' ')
       << "] Quantity: " << std::setw(m_widthField) << m_quantity
       << "Description: " << m_description;
  } else {
    os << std::left << std::setw(m_widthField) << m_name << '['
       << std::setw(serialWidth) << std::right << std::setfill('0')
       << m_serialNumber << ']' << std::setfill(' ');
  }

  os << std::endl;
}