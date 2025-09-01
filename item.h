#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(int id, const std::string &name, int quantity);

    int getId() const;
    std::string getName() const;
    int getQuantity() const;

    void setName(const std::string &name);
    void setQuantity(int quantity);

private:
    int id;
    std::string name;
    int quantity;
};

#endif // ITEM_H