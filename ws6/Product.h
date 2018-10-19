#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include "iProduct.h"

namespace w6 {
class Product : public iProduct {
   public:
    Product(int number, double price)
        : productNum{number}, productCost{price} {}
    auto getPrice() const -> double { return productCost; }
    auto display(std::ostream& out) const -> void;

   private:
    int productNum;
    double productCost;
};
}  // namespace w6

#endif