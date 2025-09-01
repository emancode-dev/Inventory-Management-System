
#include <vector>
#include "Item.h"

class Inventory {
public:
    void addItem();
    void viewItems() const;
    void updateItem();
    void deleteItem();
private:
    std::vector<Item> items;
    int generateId() const;
};

