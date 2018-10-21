// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <fstream>
#include <iostream>
#include "iProduct.h"

namespace w6 {

/**
 * Display the contents of a product along with a new line.
 *
 */
std::ostream& operator<<(std::ostream& out, const iProduct& product);

/**
 * Return a iProduct after reading an entry from file. If the file is not
 * open or it has reached end of file it will return nullptr.
 *
 * Also in case of an invalid tax type throws std::string with an error
 * message.
 *
 */
iProduct* readProduct(std::ifstream& file);
}  // namespace w6
#endif