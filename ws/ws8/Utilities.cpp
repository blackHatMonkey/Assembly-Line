#include <memory>

#include "Element.h"
#include "List.h"
#include "Utilities.h"

using namespace std;

namespace w8 {
List<Product> mergeRaw(const List<Description>& desc,
                       const List<Price>& price) {
  List<Product> priceList;
  // TODO needs comments
  for (auto i = 0u; i < desc.size(); i++) {
    for (auto j = 0u; j < price.size(); j++) {
      if (desc[i].code == price[j].code) {
        auto temp = new Product(desc[i].desc, price[j].price);
        try {
          temp->validate();
          priceList += temp;
        } catch (...) {
          delete temp;
          throw;
        }
        delete temp;
      }
    }
  }

  return priceList;
}

List<Product> mergeSmart(const List<Description>& desc,
                         const List<Price>& price) {
  List<Product> priceList;
// TODO needs commenting
  for (auto i = 0u; i < desc.size(); i++) {
    for (auto j = 0u; j < price.size(); j++) {
      if (desc[i].code == price[j].code) {
        std::unique_ptr<Product> temp(
            new Product(desc[i].desc, price[j].price));

        temp->validate();
        priceList += temp;
      }
    }
  }

  return priceList;
}
}  // namespace w8