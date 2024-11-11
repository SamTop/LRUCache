#include <iostream>
#include "ProductService.h"

int main() {
    ProductService productService(2);

    auto product1 = productService.getProductDetails(1);
    auto product2 = productService.getProductDetails(2);

    auto product3 = productService.getProductDetails(3);
    product1 = productService.getProductDetails(1);
    product2 = productService.getProductDetails(2);

    return 0;
}
