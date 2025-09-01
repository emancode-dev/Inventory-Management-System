#include "Item.h"

Item::Item(int id, const std::string &name, int quantity) : id(id), name(name), quantity(quantity) {}

int Item::getId() const {
    return id;
}

std::string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(const std::string &name) {
    this->name = name;
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
}