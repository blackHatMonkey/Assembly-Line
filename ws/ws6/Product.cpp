// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iomanip>
#include <iostream>

#include "Product.h"

namespace w6 {

/**
 * Display the product information in the following format:
 *
 * <------16------><------16------>
 *  product number  product price
 *
 * No new line is added at the end.
 *
 */
auto Product::display(std::ostream& out) const -> void {
    out << std::setw(11) << " " << std::setw(5) << std::setfill('0')
        << productNum << std::setfill(' ') << std::setw(16) << productCost;
}

}  // namespace w6
