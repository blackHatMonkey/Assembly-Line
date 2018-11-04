#include <iostream>
#include <string>

#include "Item.h"
#include "Utilities.h"

// TODO what do you do when exception happen?

Item::Item(const std::string &line) {
  Utilities util;
  auto more = true;
  auto pos = (size_t)0;

  // TODO why do we even need more since we can assume the 4 item structure?
  try {
    util.extractToken(line, pos, more);
  } catch (std::string &str) {
    std::cerr << str;
  } catch (...) {
    std::cerr << "Something went wrong when creating an item!";
  }
}

auto Item::getName() const -> const std::string & { return m_name; }

auto Item::getSerialNumber() -> const unsigned int { return m_serialNumber; }

auto Item::getQuantity() -> const unsigned int { return m_quantity; }

auto Item::updateQuantity() -> void {
  if (m_quantity > 0) {
    m_quantity--;
  }
}

auto Item::display(std::ostream &os, bool full) const -> void {}