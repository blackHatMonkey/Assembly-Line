// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "TaxableProduct.h"

namespace w6 {
// HST = 13%, PST = 8%
double TaxableProduct::taxRates[]{0.13, 0.08};

/**
 * Return the product price.
 *
 */
auto TaxableProduct::getPrice() const -> double {
    auto basePrice = Product::getPrice();

    if (isHst) {
        return (basePrice * taxRates[0]) + basePrice;
    } else {
        return (basePrice * taxRates[1]) + basePrice;
    }
}

/**
 * Display the product information. It does not add a new line
 * at the end.
 *
 */
auto TaxableProduct::display(std::ostream& out) const -> void {
    Product::display(out);
    out << (isHst ? " HST" : " PST");
}

}  // namespace w6
