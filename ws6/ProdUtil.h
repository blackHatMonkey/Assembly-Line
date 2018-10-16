// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <fstream>
#include <iostream>
#include "iProduct.h"

namespace w6 {
std::ostream& operator<<(std::ostream& out, const iProduct& product);
iProduct* readProduct(std::ifstream& file);
}  // namespace w6
#endif