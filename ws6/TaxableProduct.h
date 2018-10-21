// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include "Product.h"

namespace w6 {

/**
 * Representing a taxable product. Holds information about it's
 * product number, price and tax type.
 *
 */
class TaxableProduct : public Product {
   public:
    // store two tax types percentage (HST, PST)
    static double taxRates[2];

    TaxableProduct(int number, double price, bool isItHst)
        : Product(number, price), isHst(isItHst) {}

    /**
     * Return the product price.
     *
     */
    auto getPrice() const -> double;

    /**
     * Display the product information. It does not add a new line
     * at the end.
     *
     */
    auto display(std::ostream& out) const -> void;

   private:
    bool isHst;
};

}  // namespace w6

#endif