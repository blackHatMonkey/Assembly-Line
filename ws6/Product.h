// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include "iProduct.h"

namespace w6 {

/**
 * Represent a product class which holds product number and price
 * for a product.
 *
 */
class Product : public iProduct {
   public:
    Product(int number, double price)
        : productNum{number}, productCost{price} {}

    /**
     * Return the price of product.
     *
     */
    auto getPrice() const -> double { return productCost; }

    /**
     * Display the product information in the following format:
     *
     * <------16------><------16------>
     *  product number  product price
     *
     * No new line is added at the end.
     *
     */
    auto display(std::ostream& out) const -> void;

   private:
    int productNum;
    double productCost;
};
}  // namespace w6

#endif