// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 02/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>

#include "Element.h"
#include "List.h"
#include "Utilities.h"

using namespace std;

namespace w8 {
List<Product> mergeRaw(const List<Description> &desc,
                       const List<Price> &price) {
  List<Product> priceList;
  // find the common elements between the two lists
  for (auto i = 0u; i < desc.size(); i++) {
    for (auto j = 0u; j < price.size(); j++) {
      if (desc[i].code == price[j].code) {
        auto temp = new Product(desc[i].desc, price[j].price);

        temp->validate();
        priceList += temp;

        delete temp;
      }
    }
  }

  return priceList;
}

List<Product> mergeSmart(const List<Description> &desc,
                         const List<Price> &price) {
  List<Product> priceList;
  // find the common elements between the two list
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
} // namespace w8