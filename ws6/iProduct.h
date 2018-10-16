// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6 {
class iProduct {
   public:
    virtual double getPrice() const = 0;
    virtual void display(std::ostream&) const = 0;
};

class Product : public iProduct {
   private:
    int productNum = 0;
    double productCost = 0.0;
};

class TaxableProduct : public Product {};

}  // namespace w6
#endif