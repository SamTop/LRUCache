#ifndef PRODUCT_H
#define PRODUCT_H

#include <vector>
#include <cstdint>
#include <string>

struct Product {
    uint64_t id;
    uint32_t category;
    std::string name;
    std::string description;
    std::vector<uint8_t> thumbnail;

    Product(uint64_t id, uint32_t category, std::string name, std::string description, std::vector<uint8_t> thumbnail)
            : id(id), category(category), name(std::move(name)), description(std::move(description)), thumbnail(std::move(thumbnail)) {}
};
#endif
