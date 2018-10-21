// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Product.h"
#include "TaxableProduct.h"
#include "iProduct.h"

namespace w6 {

/**
 * Display the contents of a product along with a new line.
 *
 */
auto operator<<(std::ostream& out, const iProduct& product) -> std::ostream& {
    product.display(out);
    out << std::endl;

    return out;
}

/**
 * Return a iProduct after reading an entry from file. If the file is not
 * open or it has reached end of file it will return nullptr.
 *
 * Also in case of an invalid tax type throws std::string with an error
 * message.
 *
 */
auto readProduct(std::ifstream& file) -> iProduct* {
    if (file.is_open()) {
        auto productNum = 0;
        auto productPrice = 0.0;
        char taxType = 0;
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
