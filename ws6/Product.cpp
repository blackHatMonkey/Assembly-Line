#include <iomanip>
#include <iostream>

#include "Product.h"

namespace w6 {
auto Product::display(std::ostream& out) const -> void {
    out << std::setw(11) << " " << std::setw(5) << std::setfill('0')
        << productNum << std::setfill(' ') << std::setw(16) << productCost;
}

}  // namespace w6
