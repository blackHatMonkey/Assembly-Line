#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Product.h"
#include "TaxableProduct.h"
#include "iProduct.h"

// TODO remove this
using std::cout;
using std::endl;

namespace w6 {

auto operator<<(std::ostream& out, const iProduct& product) -> std::ostream& {
    product.display(out);
    out << std::endl;

    return out;
}

auto readProduct(std::ifstream& file) -> iProduct* {
    if (file.is_open()) {
        auto productNum{0};
        auto productPrice{0.0};
        char taxType{0};
        std::string line;

        std::getline(file, line);
        std::istringstream iss(line);

        iss >> productNum >> productPrice >> taxType;
        if (!file.eof()) {
            switch (taxType) {
                case 0:
                    return new Product(productNum, productPrice);
                    break;
                case 'H':
                    return new TaxableProduct(productNum, productPrice, true);
                    break;
                case 'P':
                    return new TaxableProduct(productNum, productPrice, false);
                    break;
                default:
                    throw std::string("Unrecognizable Tax Code!");
            }
        } else {
            return nullptr;
        }
    }
    return nullptr;
}

}  // namespace w6
