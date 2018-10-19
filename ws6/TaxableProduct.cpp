
#include "TaxableProduct.h"

namespace w6 {

double TaxableProduct::taxRates[]{0.13, 0.08};

auto TaxableProduct::getPrice() const -> double {
    auto basePrice = Product::getPrice();

    if (isHst) {
        return (basePrice * taxRates[0]) + basePrice;
    } else {
        return (basePrice * taxRates[1]) + basePrice;
    }
}

auto TaxableProduct::display(std::ostream& out) const -> void {
    Product::display(out);
    out << (isHst ? " HST" : " PST");
}

}  // namespace w6
