#ifndef PRODUCTDATABASE_H
#define PRODUCTDATABASE_H

#include <optional>
#include <unordered_map>
#include "Product.h"

class ProductDatabase {
public:
    ProductDatabase() {
        products_.insert({1, Product(1, 101, "Laptop", "A high-end laptop", {0x81, 0x13, 0x45, 0x47})});
        products_.insert({2, Product(2, 102, "Phone", "A smartphone", {0x17, 0x41, 0xA6, 0x3F})});
        products_.insert({3, Product(3, 101, "Tablet", "A tablet device", {0x12, 0x43, 0x4F, 0xF0})});
    }


    std::optional<Product> fetchProduct(uint64_t id) {
        auto it = products_.find(id);
        if (it != products_.end()) {
            return it->second;
        }
        return std::nullopt;
    }
private:
    std::unordered_map<uint64_t, Product> products_;
};

#endif

