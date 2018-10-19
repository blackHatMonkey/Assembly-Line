#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include "Product.h"

namespace w6 {

class TaxableProduct : public Product {
   public:
    static double taxRates[2];
    TaxableProduct(int number, double price, bool isItHst)
        : Product(number, price), isHst{isItHst} {}
    auto getPrice() const -> double;
    auto display(std::ostream& out) const -> void;

   private:
    bool isHst;
};

}  // namespace w6

#endif