#include <iostream>
#include "Inventory.h"

void displayMenu() {
    std::cout << "Inventory Management System" << std::endl;
    std::cout << "1. Add Item" << std::endl;
    std::cout << "2. View Items" << std::endl;
    std::cout << "3. Update Item" << std::endl;
    std::cout << "4. Delete Item" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.viewItems();
                break;
            case 3:
                inventory.updateItem();
                break;
            case 4:
                inventory.deleteItem();
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}