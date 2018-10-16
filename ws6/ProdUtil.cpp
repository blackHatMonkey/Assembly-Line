#include <fstream>
#include <iostream>
#include "iProduct.h"

namespace w6 {
std::ostream& operator<<(std::ostream& out, const iProduct& product) {
    product.display(out);
    return out;
}
iProduct* readProduct(std::ifstream& file);
}  // namespace w6