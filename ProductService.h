#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

#include <optional>
#include <cstdint>
#include "LRUCache.h"
#include "Product.h"
#include "ProductDatabase.h"

class ProductService {
public:
    ProductService(size_t cacheCapacity) : cache_(cacheCapacity), db_() {}

    std::optional<Product> getProductDetails(uint64_t id) {
        auto cachedProduct = cache_.get(id);
        if (cachedProduct) {
            return cachedProduct;
        }

        auto product = db_.fetchProduct(id);
        if (product) {
            cache_.put(id, *product);
        }
        return product;
    }

private:
    LRUCache<uint64_t, Product> cache_;
    ProductDatabase db_;
};

#endif
