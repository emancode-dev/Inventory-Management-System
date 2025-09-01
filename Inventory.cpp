#include "Inventory.h"
#include <iostream>
#include <limits>

int Inventory::generateId() const {
    return items.empty() ? 1 : items.back().getId() + 1;
}

void Inventory::addItem() {
    std::string name;
    int quantity;

    std::cout << "Enter item name: ";
    std::cin >> name;

    while (true) {
        std::cout << "Enter item quantity: ";
        if (std::cin >> quantity) {
            break; // valid input
        } else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        }
    }


    int id = generateId();
    items.emplace_back(id, name, quantity);

    std::cout << "Item added successfully." << std::endl;
}

void Inventory::viewItems() const {
    if (items.empty()) {
        std::cout << "No items in inventory." << std::endl;
        return;
    }

    std::cout << "ID\tName\tQuantity" << std::endl;
    for (const auto &item : items) {
        std::cout << item.getId() << "\t" << item.getName() << "\t" << item.getQuantity() << std::endl;
    }
}

void Inventory::updateItem() {
    int id;
    std::cout << "Enter item ID to update: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid ID." << std::endl;
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        return; // exit the function
    }


    for (auto &item : items) {
        if (item.getId() == id) {
            std::string name;
            int quantity;

            std::cout << "Enter new item name: ";
            std::cin >> name;
            std::cout << "Enter new item quantity: ";
            std::cin >> quantity;

            item.setName(name);
            item.setQuantity(quantity);

            std::cout << "Item updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Item not found." << std::endl;
}

void Inventory::deleteItem() {
    int id;
    std::cout << "Enter item ID to delete: ";
    std::cin >> id;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid ID." << std::endl;
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        return; // exit the function
    }


    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getId() == id) {
            items.erase(it);
            std::cout << "Item deleted successfully." << std::endl;
            return;
        }
    }
}
//command:
// g++ -Wall -Wextra -g3 main.cpp Inventory.cpp item.cpp -o inventory.exe
// .\inventory.exe